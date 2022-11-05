## Leading Question 

Our leading question is that given an infectious virus appearing in a specific city in the United States, how will the pandemic develops as virus spreads along the road network and airline. We will set a few hyperparameters for the virus, like the number of days that the virus starts to spread from patients after they are infected, and the percentage of infection caused by the virus in the population. We also set a respond time for the government to take actions to cut the road networks as the number of infection reach a certain number. From these characteristics of the virus, we will predict how long each state would have an infection and the path that the virus will follow. 

## Dataset Acquisition

Our datasets, OpenFlights and Road Networks and Points of Interest, are both provided on the document of CS225. We downloads the datasets from the official website listed in the document. 

## Data Format

The first dataset we use is OpenFlights. The dataset consists of the information about the names, locations, and types of the airports all over the world. There are in total 7698 items in the OpenFlights dataset, which are listed in a dat file. We plan to only use a subset of the dataset defined as all the airports located in North America (i.e. Canada, United States, and Mexico). The second dataset is Road Networks and Points of Interest from University of Utah, and we are going to use the Road Network of North American among all the datasets it provides. The dataset includes all the roads among cities in North America, and the coordinates of each city is genereated with a coordinate system created by the author. The dataset contains 175813 cities in America and 179179 roads. We will only use a subset of the dataset by selecting the cities with airports included in the airport dataset previous mentioned. 

## Data Correction

There are several aspects that we can check whether the datasets we use have errors. 

1. If we find that the degree of the nodes with airport is 0 in the graph, it will be likely to be an error which caused by the probability that a city with airport is not connected to other cities although it's very low. 

2. The latitude and longitude of the datasets are not between $[-90, 90]$ and $[-180, 180]$ will be considered as a kind of error. For the second dataset, the coordinates for each node should not be smaller than 0 either for x or y axis because all the nodes in the graph are shown in the first quadrant. 

3. The nodes in the graph should be corresponding to the actual situation. For example, the cities in states like Utah and Colorado should have much less degrees compared to those of cities in New York and Illinois. 

## Data Storage

The graph we are using is undirectd graph with no self loop but may contains multiple edges. The weight of each edge is defined as the time needed to travel between the nodes on each side. To store this graph, we are planning to use a variant of adjacent list which is easy to keep the space complexity the least. The code for the data structure is given below:

```C++
struct edge {
    node u; 
    node v;
    int w;
    size_t next;
};

# Add a directed edge from node u to node v with weight w
void addEdge(int u, int v, int w, map<node, size_t>& head, vector<node>& edgeList) {
    edgeList.push_back({u, v, w, head[u]});
    head[u] = edgeList.size() - 1;
}

void traverse(int u, const map<node, size_t>& head, const vector<node>& edgeList) {
    for (size_t i = head[u]; i; i = edgeList[i].next) {
        operate(edgeList[i]});
    }
}

```

In this data structure, the edge list contains all the edges of the graph, and its space complexity is $O(m)$. The vector head contains the mapping between each node and the first edge it has, so it should be $O(n)$. Therefore, the total time complexity of the data structure should be $O(m + n)$. The time complexity for adding all the edges to the edge list is $O(m)$, and the time complexity for traversing the neightbors of a node is $O(deg(v))$. 

## Algorithm 

We will use BFS to generate a sequence of nodes which start from the start point that we specify. The seqence will be useful in the visualization of the graph. The inputs of the function would be the graph that we built and a start node. The output of the function is a vector of all nodes in the order of visit. The time complexity of the function is $O(n + m)$.

We will use Dijkstra to figure out the distance between each node and the starting node. The inputs of the function are the graph and the starting point. The output will be a map with key be a node and the value be a size_t, mapping each node to the distance from the starting point. The time complexity of Dijkstra algorithm is $O(n log n + m log n)$. Based on the dataset we have, we expect the number of nodes and edges to be very large. Therefore, we will also use iteravtive deepening DFS for this function. 

We will use Prim to come up with a MST between the cities because we expect the graph to be a dense graph. It will be useful when we want to know about the minimum cost we need to connect all cities together. The inputs of the function are a graph and a starting point. The output will be a MST spanned from the graph. The time complexity of Prim is $O(n^2)$.

We will use maximum flow to calculate the time needed for the virus to spread from one starting point to the the endpoint. Since there are multiple paths from a node to another, we cannot simply calculate the time needed to spread as the shortest path between the nodes. The function input is the graph, a startpoint, and an endpoint. The output is simply a size_t number representing the time needed to spread to endpoint. Maximum flow using Dinic will have a time complexity of $O(n^2 m). The algorithm will be very slow dealing with large data set and we will only use it for smaller subset of our data. 

We will use projection on to map based on the data to generate a visualization of the graph as our dataset is created from the real map. The inputs of the function are a graph and a reference to a drawing utility which is adaptable. The function will have not inputs but draw the picture of the graph into the drawing utility. We expect the time complexity of the function to be $O(n + m)$.



## Timeline

Week 1 (Oct. 30 - Nov. 5): Complete team contract, proposal, and GitHub repo creation. Find aapropriate dataset and analyze the data.

Week 2 (Nov. 6 - Nov. 12): Finish data processing and program skeleton.

Week 3 (Nov. 13 - Nov. 19): Learn about unfamiliar algorithms and start implementation of the algorithms.

Mid-Project Checkin at Week 3

Week 4 (Nov. 20 - Nov. 26): Finish most of the implementations of the algorithm and start final presentation preparation.

Week 5 (Nov. 27 - Dec. 3): Finish all the algorithms if any and continue to work to final presentation.

Week 6 (Dec. 4 - Dec. 10): Finish presentaion preparation.

Final project due Dec. 8.