#include "../lib/data/file.h"
#include "test.h"

using namespace data;

TEST_CASE("Test read_file", "[file]") {
    auto data = read_file("../data/airports.dat");

    REQUIRE(data[353][0] == "357");
    REQUIRE(data[467][1] == "Leicester Airport");
    REQUIRE(data[847][2] == "Vryburg");
    REQUIRE(data[1401][3] == "France");
    REQUIRE(data[1507][4] == "VIC");
    REQUIRE(data[2118][5] == "OPMF");
    REQUIRE(data[3000][6] == "16.82430076599121");
    REQUIRE(data[3067][7] == "127.38099670410156");
    REQUIRE(data[4013][8] == "67");
    REQUIRE(data[4607][9] == "5");
    REQUIRE(data[5431][10] == "A");
    REQUIRE(data[7454][11] == "");
    REQUIRE(data[6255][12] == "airport");
    REQUIRE(data[113][13] == "OurAirports");
}

TEST_CASE("Test split data", "[file]") {
    auto list1 = split_string("To be or not to be, this is a question\n", ' ');
    REQUIRE(list1.size() == 10);
    REQUIRE(list1[0] == "To");
    REQUIRE(list1[5] == "be,");

    auto list2 = split_string("This  is  // a ??? tes! cåse\n", ' ');

    REQUIRE(list2.size() == 9);
    REQUIRE(list2[1] == "");
    REQUIRE(list2.back() == "cåse");
}

TEST_CASE("Test trim", "[file]") {
    REQUIRE(trim(" abc ") == "abc");
    REQUIRE(trim("\"\"\" k \"\"") == "k");
    REQUIRE(trim("  \\N\"\"") == "");
}