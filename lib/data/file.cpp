#include "file.h"
using namespace std;

vector<vector<string>> data::read_file(string filename, char sep) {
    ifstream ifs(filename);

    if (! ifs.is_open()) throw std::invalid_argument("File not found at read_file");

    std::string line;

    vector<vector<string>> matrix;

    while (getline(ifs, line)) {
        size_t cnt = 0;

        for (auto& c : line) {
            if (c == '\"') cnt++;

            if (c == sep && cnt & 1) c = ' '; 
        }

        matrix.push_back(split_string(line, sep));
    }

    return matrix;
}

vector<string> data::split_string(string str, char sep) {
    vector<string> split;

    while (! str.empty()) {
        if (str.find(sep) == string::npos) {
            split.push_back(trim(str.substr(0, str.length() - 1)));
            break;
        }

        split.push_back(trim(str.substr(0, str.find(sep))));
        str = str.substr(str.find(sep) + 1);
    }

    return split;
}


string data::trim(string str) {
    size_t i = 0, j = str.length() - 1;

    while (i < str.length() && (str[i] == ' ' || str[i] == '\"')) i++;
    while (j < str.length() && (str[j] == ' ' || str[j] == '\"')) j--;

    return j < i || str.substr(i, j - i + 1) == "\\N"? "" : str.substr(i, j - i + 1);
}