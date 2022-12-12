#include "test.h"
#include "../src/spread.h"
#include "../src/load_files.h"

using namespace test;

#define start "Chicago,IL"

static auto Map = *(csv_to_graph());

TEST_CASE("Test spread nextStep", "[spread]") {
    Spread s(Map, start, 5);

    set<Vertex*> latency, infected;

    for (int _ = 0; _ < 100; _++) {
        s.nextStep();
        for (const auto& it : s.getStatus()) {
            if (latency.find(it.first) != latency.end()) {
                REQUIRE(it.second != "N");

                if (it.second == "I") {
                    latency.erase(it.first);
                    infected.insert(it.first);
                }
            } else if (infected.find(it.first) != infected.end()) {
                REQUIRE(it.second == "I");
            } else {
                REQUIRE(it.second != "I");

                if (it.second == "L") {
                    latency.insert(it.first);
                }
            }
        }
    }
}

TEST_CASE("Test spread randomness", "[spread]") {
    Spread s1(Map, start, 5);
    Spread s2(Map, start, 5);
    Spread s3(Map, start, 5);

    for (int _ = 0; _ < 10; _++) {
        s1.nextStep();
        s2.nextStep();
        s3.nextStep();
    }

    REQUIRE(s1.getStatus() != s2.getStatus());
    REQUIRE(s1.getStatus() != s3.getStatus());
    REQUIRE(s2.getStatus() != s3.getStatus());
}