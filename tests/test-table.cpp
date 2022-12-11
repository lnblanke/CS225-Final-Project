#include "../lib/data/table.h"
#include "test.h"

using namespace data;

TEST_CASE("Test Table addColumn basic", "[table]") {
    Table t;

    REQUIRE(t.getNumCols() == 0);
    REQUIRE(t.getNumRows() == 0);

    t.addColumn("test1");

    REQUIRE(t.getNumCols() == 1);
    REQUIRE(t.getNumRows() == 0);

    t.addRows(4);

    REQUIRE(t.getNumRows() == 4);

    t.addColumn("test2");

    REQUIRE(t.getNumRows() == 4);
    REQUIRE(t.getNumCols() == 2);
}

TEST_CASE("Test table addColumn with operators", "[table]") {
    Table t;
    t.addRows(4);

    t.addColumn("test1");

    REQUIRE(t.getNumRows() == 0);
    REQUIRE(t[0].getType() == "");

    t.addRows(2);
    t.setItem(1, 0, "");
    REQUIRE(t[0].getType() == "");
    t.setItem(0, 0, "1");
    REQUIRE(t[0].getName() == "test1");
    REQUIRE(t[0].getType() == "numeric");
    REQUIRE(&t[0] == &t["test1"]);
    REQUIRE(t[0].getName() == t.getColName(0));
    REQUIRE(t[0].getType() == t.getColType(0));
    REQUIRE(t[0].size() == t.getNumRows());

    REQUIRE(t.getItem(1, 0) == "0");

    t.addColumn("test2");
    t.addRows(5);
    t.setItem(3, 1, "test");

    REQUIRE(t.getNumCols() == 2);
    REQUIRE(t[0].size() == 5);
    REQUIRE(t[1].size() == 5);
    REQUIRE(t[1].getType() == "categorical");

    try {
        t.addColumn("test2");

        REQUIRE(0);
    } catch (invalid_argument& e) {}

    try {
        auto c = t[2];

        REQUIRE(0);
    } catch (invalid_argument& e) {}

    try {
        auto c = t["test3"];

        REQUIRE(0);
    } catch (invalid_argument& e) {}
}

TEST_CASE("Test Table set and get", "[table]") {
    Table t;
    t.addColumn("1");
    t.addColumn("2");
    t.addColumn("3");
    t.addRows(3);

    t.setItem(1, 0, "1");
    t.setItem(0, 1, "3.14");
    t.setItem(0, 2, ":)");

    REQUIRE(std::stoi(t.getItem(0, 0)) == 0);
    REQUIRE(std::stoi(t.getItem(1, 0)) == 1);
    REQUIRE(std::stod(t.getItem(0, 1)) == 3.14);
    REQUIRE(t.getItem(0, 2) == ":)");

    try {
        t.setItem(3, 0, "1");
    
        REQUIRE(0);
    } catch (invalid_argument& e) {}

    try {
        t.setItem(0, 3, "c");
        
        REQUIRE(0);
    } catch (invalid_argument& e) {}

    try {
        t.setItem(0, 0, "a");

        REQUIRE(0);
    } catch (invalid_argument& e) {}

    try {
        t.setItem(2, 1, "CS225");

        REQUIRE(0);
    } catch (invalid_argument& e) {}

    try {
        t.getItem(3, 0);

        REQUIRE(0);
    } catch (invalid_argument& e) {}

    try {
        t.getItem(0, 3);

        REQUIRE(0);
    } catch (invalid_argument& e) {}
}