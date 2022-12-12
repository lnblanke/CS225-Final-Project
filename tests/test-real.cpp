#include "test.h"
#include "../src/load_files.h"
#include "../lib/algorithm/bfs.h"
#include "../lib/algorithm/dijkstra.h"

static auto Map = *(csv_to_graph());

TEST_CASE("Test BFS real", "[bfs]") {
    map<Vertex*, size_t> depth;
    
    REQUIRE(algorithm::bfs(Map, Map.getVertex("Chicago,IL"), Map.getVertex("Seattle,WA"), depth));

    REQUIRE(depth[Map.getVertex("Champaign,IL")] == 2);
    REQUIRE(depth[Map.getVertex("Dallas,TX")] == 2);
    REQUIRE(depth[Map.getVertex("Miami,FL")] == 2);
    REQUIRE(depth[Map.getVertex("Washington,DC")] == 2);
}

TEST_CASE("Test Dijkstra real", "[dijkstra]") {
    auto result = algorithm::dijkstra(Map, Map.getVertex("San Francisco,CA"));

    REQUIRE(result[Map.getVertex("Los Angeles,CA")] - 2.5133830107 <= 1e-8);
    REQUIRE(result[Map.getVertex("Boston,MA")] - 7.9799174235 <= 1e-8);
    REQUIRE(result[Map.getVertex("New York,NY")] - 7.4937890716 <= 1e-8);
    REQUIRE(result[Map.getVertex("Champaign,IL")] - 7.5332856004 <= 1e-8);
    REQUIRE(result[Map.getVertex("Las Vegas,NV")] - 2.5540219433 <= 1e-8);
}