#ifndef KDTREE_H
#define KDTREE_H

#include <vector>
#include "../graph/city.h"
using std::vector;
using graph::City;

#define point vector<double>
#define vec(city) vector<double>{city->getLatitude(), city->getLongitude()}

class KDTree {
private:
  struct TreeNode {
    City* c;
    TreeNode* left, *right;

    TreeNode(City* city): c(city), left(nullptr), right(nullptr) {}
  };

  TreeNode* root;

  bool smaller(const point& p1, const point& p2, int cur2) const {
    if (p1[cur2] == p2[cur2]) return p1 < p2;
    return p1[cur2] < p2[cur2];
  }

  bool shouldReplace(const point& target,
                     const point& currentBest,
                     const point& potential) const
  {
      double best = 0, cur = 0;

      for (int i = 0; i < 2; i++) {
        best += (target[i] - currentBest[i]) * (target[i] - currentBest[i]);
        cur += (target[i] - potential[i]) * (target[i] - potential[i]);
      }

      return cur < best || (cur == best && potential < currentBest);
  }

  int quickSelect(std::vector<City*>& v, int l, int r, int kth, int sp) {
    if (l == r) return l;

    int p = l;

    for (int i = l + 1; i <= r; i++) {
      if (smaller(vec(v[i]), vec(v[l]), sp)) {
        std::swap(v[i], v[++p]);
      } 
    }

    std::swap(v[p], v[l]);

    if (p - l + 1 > kth) return quickSelect(v, l, p, kth, sp);
    else return quickSelect(v, p + 1, r, kth - (p + 1 - l), sp);
  }

  void addPoint(TreeNode*& root, vector<City*> v, int sp) {
    if (v.empty()) return;

    int n = v.size(), mid = (n - 1) >> 1;
    int idx = quickSelect(v, 0, n - 1, mid, sp);
    root = new TreeNode(v[idx]);
    addPoint(root->left, vector(v.begin(), v.begin() + idx), sp ^ 1);
    addPoint(root->right, vector(v.begin() + idx + 1, v.end()), sp ^ 1);
  }

  City* query(TreeNode* root, const point& p, int sp) const {
    if (! root->left && ! root->right) {
      return root->c;
    }

    City* ans = root->c;

    if (smaller(p, vec(root->c), sp)) {
      if (! root->left) ans = root->c;
      else ans = query(root->left, p, sp ^ 1);

      if (shouldReplace(p, vec(ans), vec(root->c))) {
        ans = root->c;
      }

      double dis = 0;
      for (int i = 0; i < 2; i++) {
        dis += (vec(ans)[i] - p[i]) * (vec(ans)[i] - p[i]);
      }

      if (root->right && (vec(root->c)[sp] - p[sp]) * (vec(root->c)[sp] - p[sp]) <= dis) {
        auto r = query(root->right, p, sp & 1);
        if (shouldReplace(p, vec(ans), vec(r))) ans = r;
      }
    } else {
      if (! root->right) ans = root->c;
      else ans = query(root->right, p, sp ^ 1);
    
      if (shouldReplace(p, vec(ans), vec(root->c))) {
        ans = root->c;
      }
      
      double dis = 0;
      
      for (int i = 0; i < 2; i++) {
        dis += (vec(ans)[i] - p[i]) * (vec(ans)[i] - p[i]);
      }

      if (root->left && (vec(root->c)[sp] - p[sp]) * (vec(root->c)[sp] - p[sp]) <= dis) {
        auto r = query(root->left, p, sp & 1);
        if (shouldReplace(p, vec(ans), vec(r))) ans = r;
      }
    }

    return ans;
  }

public:
  KDTree(const vector<City*>& v) {
    addPoint(root, v, 0);
  }

  City* findNearestNeighbor(const point& q) const
  {
      return query(root, q, 0); 
  }
};

#endif