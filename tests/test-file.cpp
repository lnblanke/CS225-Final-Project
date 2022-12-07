#include "../lib/data/file.h"
#include "test.h"

using namespace data;

/*
This test is not finished
*/

TEST_CASE("Test read_file airport.dat", "[file]") {
    auto data = read_file("../data/airports.dat");

    // @TODO
}