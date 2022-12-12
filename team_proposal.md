## Leading Question 

Our leading question is that given an infectious virus appearing in a specific city in the United States, how will the pandemic develops in the country as virus spreads along the road network and airlines. We allow users to adjust the parameters of the virus, like the number of days after infection that the patients would have symptoms, and the number of days they would stay infected before recovery. We also assume that the government would take actions by cutting the connections between infected cities and uninfected cities to avoid large infection cases in big cities like New York and Los Angeles. From these characteristics of the virus, we will predict how long each state would have an infection and the path that the virus will follow. 

## Dataset Acquisition and Processing

## Data Format
We are going to use three datasets in total. 

1. City and Town Population Totals: 2020-2021 by United States Census Bureau

Dataset link: <a href = "https://www.census.gov/data/tables/time-series/demo/popest/2020s-total-cities-and-towns.html#ds"> https://www.census.gov/data/tables/time-series/demo/popest/2020s-total-cities-and-towns.html#ds </a>

The dataset consists of the population of all cities and town populations and is stored in a csv file. The dataset contains 81417 entries in total and we are going to use all of them. 

2. Airport, airline and route data by OpenFlights 

Dataset link: <a href = "https://openflights.org/data.html"> https://openflights.org/data.html </a>

The dataset contains all the airports around the world stored in dat file with csv format. There are 14110 airports and 67663 routes between airports. We will only use airports in US and domestic routes. 

3. Real Datasets for Spatial Databases: Road Networks and Points of Interest by University of Utah

Dataset link: <a href = "https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm"> https://www.cs.utah.edu/~lifeifei/SpatialDataset.htm </a>

The dataset includes all the cities in North America and roads between them in csv format. There are in total 175813 vertices and 179179 edges in the dataset. We are going to use only the cities in the United States and roads between them. 

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

We will use Dijkstra to figure out the distance between each node and the starting node. The inputs of the function are the graph and the starting point. The output will be a map with key be a node and the value be a size_t, mapping each node to the distance from the starting point. The time complexity of Dijkstra algorithm is $O(n log n + m log n)$.

We will use maximum flow to calculate the time needed for the virus to spread from one starting point to the the endpoint. Since there are multiple paths from a node to another, we cannot simply calculate the time needed to spread as the shortest path between the nodes. The function input is the graph, a startpoint, and an endpoint. The output is simply a size_t number representing the time needed to spread to endpoint. Maximum flow using Dinic will have a time complexity of $O(n^2 m)$. The algorithm will be very slow dealing with large data set and we will only use it for smaller subset of our data. 

Both BFS and DFS are neccessary for maximum flow so we will use both in the project. The inputs of BFS algorithm should be a graph and a starting point, and the output should be a bool representing whether we are able to reach the endpoint we are seeking for. The inputs of DFS algorithm should be a graph, a starting point and an integer representing current flow, and the output would be a number that stands for the amount of increased flow. Both BFS and DFS should have time complexity of $O(n + m)$.

We also use Tarjan to detect cycles in our graph and thus check whether there could be possible intersections of infection. The inputs of the algorithm should be a graph, and it returns a bool representing whether current existed edges can form cycles. The time complexity of Tarjan algorithm is $O(n + m)$.

## Timeline

Week 1 (Oct. 30 - Nov. 5): Complete team contract, proposal, and GitHub repo creation. Find aapropriate dataset and analyze the data.

Week 2 (Nov. 6 - Nov. 12): Finish data processing and program skeleton.

Week 3 (Nov. 13 - Nov. 19): Learn about unfamiliar algorithms and start implementation of the algorithms. BFS, DFS, Tarjan, and Dijkstra should be finished this week.

Mid-Project Checkin at Week 3

Week 4 (Nov. 20 - Nov. 26): Finish most of the implementations of the algorithm and start final presentation preparation. Maximum flow algorithm should be completed in this week. Tests for all algorithms should be added. 

Week 5 (Nov. 27 - Dec. 3): Finish all the algorithms if any and continue to work to final presentation.

Week 6 (Dec. 4 - Dec. 10): Finish presentaion preparation.

Final project due Dec. 8.