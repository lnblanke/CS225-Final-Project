## Final Project Report

### Implementations
- [```Graph```](lib/graph/graph.h)

    We use graph as a primary data structure for storing the cities and connections between them. Each city is represented by a [```Vertex```](lib/graph/vertex.h) object and its subclass [```City```](lib/graph/city.h) object. An edge is represented by a [```Edge```](lib/graph/edge.h) object. We tested the class with different operations ([tests](tests/test-graph.cpp)) on it and it worked well on our datasets.
- [```File```](lib/data/file.h)

    The file functions are used to read the datasets stored in csv format and transform them into 2D vector, with each entries trimed. We tested it with entries in the dataset ([test](tests/test-file.cpp)). 

- [```Table```](lib/data/table.h)

    We used the ```Table``` class to simulate a table so that we could process our data simply and efficiently. We tested using different operations on the class ([test](tests/test-table.cpp)). 

- [```BFS```](lib/algorithm/bfs.h)

    ```BFS``` algorithm is part of the ```Dinic``` algorithm. It is used to detect the distance between each node to the origin point. We tested the algorithm using graph with small(~5), middle(~10), and large(~20) scales of nodes ([test](tests/test-bfs.cpp)) as well as tests on our datasets ([tests](tests/test-real.cpp))

- [```DFS```](lib/algorithm/dfs.h)

    ```DFS``` algorithm is also part of ```Dinic``` algorithm. It find a path from ```source``` to ```sink``` with maximum flow. We did small scale tests on the algorithm ([test](tests/test-dfs.cpp)), while larger tests are done with ```Dinic``` algorithm, which is easier for us to test.

- [```Dijkstra```](lib/algorithm/dijkstra.h)

    ```Dijkstra``` algorithm is used to calculat single source shortest path (SSSP), which is used as part of the probability of spreading virus from a city to another. We did small, middle, and large scale tests on ```Dijkstra``` ([tests](tests/test-dijkstra.cpp)) as well as tests on our datasets ([tests](tests/test-real.cpp)).

- [```Dinic```](lib/algorithm/dinic.h)

    ```Dinic``` algorithm is adopted to find the minimum cost for blocking a list of cities. We did small, middle, and large scale tests on ```Dinic``` ([test](tests/test-dinic.cpp)).

- [```KD-tree```](lib/algorithm/kd-tree.h)

    We adopted ```KD tree``` to find the nearest neighbor for a given point, which is part of the processing where we need to combine two datasets with points. We did small and middle scale tests on the algorithm ([tests](tests/test-kdtree.cpp))

- [```Tarjan```](lib/algorithm/tarjan.h)

    We used ```Tarjan``` to find out whether there are cycles in infected cities. We did small, middle, and large scale tests on the algorithm ([tests](tests/test-tarjan.cpp))

### Conclusion

Our leading question is that given an infectious virus appearing in a specific city in the United States, how will the pandemic develops in the country as virus spreads along the road network and airlines.
We answered our leading question by creating a simulator of the virus at the end to create a visualization of our algorithms. By the simulator, we found out that the virus spreads out very fast if we set up a relative small latency period. For example, the number of infected cities over 30 days after the apperance of virus would be about 1/3 of the total number of cities in the United States. Larger cities that are far away from the origin of virus are more likely to be infected compared to nearby cities with small population. We also found out that with blocking enacting on a few cities, the pandemic could be control a little better but the number of infected cities would still increase as time goes. 