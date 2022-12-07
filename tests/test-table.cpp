// #include "../lib/data/table.h"
// #include "test.h"

// using namespace data;

// TEST_CASE("Test Table addColumn basic", "[table]") {
//     Table t;

//     REQUIRE(t.getNumCols() == 0);
//     REQUIRE(t.getNumRows() == 0);

//     t.addColumn("test1", "int");

//     REQUIRE(t.getNumCols() == 1);
//     REQUIRE(t.getNumRows() == 0);

//     t.addRows(4);

//     REQUIRE(t.getNumRows() == 4);

//     t.addColumn("test2", "double");

//     REQUIRE(t.getNumRows() == 4);
//     REQUIRE(t.getNumCols() == 2);
// }

// TEST_CASE("Test table addColumn with operators", "[table]") {
//     Table t;
//     t.addRows(4);

//     t.addColumn("test1", "int");

//     REQUIRE(t.getNumRows() == 0);
//     REQUIRE(t[0]->getName() == "test1");
//     REQUIRE(t[0]->getType() == "int");
//     REQUIRE(t[0] == t["test1"]);
//     REQUIRE(t[0]->getName() == t.getColName(0));
//     REQUIRE(t[0]->getType() == t.getColType(0));
//     REQUIRE(t[0]->size() == t.getNumRows());

//     t.addColumn("test2", "double");
//     t.addRows(5);

//     REQUIRE(t.getNumCols() == 2);
//     REQUIRE(t[0]->size() == 5);
//     REQUIRE(t[1]->size() == 5);

//     try {
//         t.addColumn("test2", "string");

//         REQUIRE(0);
//     } catch (invalid_argument& e) {}

//     try {
//         t.addColumn("test3", "long");
        
//         REQUIRE(0);
//     } catch (invalid_argument& e) {}

//     try {
//         auto c = t[2];

//         REQUIRE(0);
//     } catch (invalid_argument& e) {}

//     try {
//         auto c = t["test3"];

//         REQUIRE(0);
//     } catch (invalid_argument& e) {}
// }

// TEST_CASE("Test Table set and get", "[table]") {
//     Table t;
//     t.addColumn("1", "int");
//     t.addColumn("2", "double");
//     t.addColumn("3", "string");
//     t.addRows(3);

//     t.setItem(0, 1, "1");
//     t.setItem(1, 0, "3.14");
//     t.setItem(2, 0, ":)");

//     REQUIRE(*(static_cast<int*>(t.getItem(0, 0))) == 0);
//     REQUIRE(*(static_cast<int*>(t.getItem(0, 1))) == 1);
//     REQUIRE(*(static_cast<double*>(t.getItem(1, 0))) == 3.14);
//     REQUIRE(*(static_cast<string*>(t.getItem(2, 0))) == ":)");

//     try {
//         t.setItem(3, 0, "1");
    
//         REQUIRE(0);
//     } catch (invalid_argument& e) {}

//     try {
//         t.setItem(0, 3, "c");
        
//         REQUIRE(0);
//     } catch (invalid_argument& e) {}

//     try {
//         t.setItem(0, 0, "a");

//         REQUIRE(0);
//     } catch (invalid_argument& e) {}

//     try {
//         t.setItem(1, 2, "CS225");

//         REQUIRE(0);
//     } catch (invalid_argument& e) {}

//     try {
//         t.getItem(3, 0);

//         REQUIRE(0);
//     } catch (invalid_argument& e) {}

//     try {
//         t.getItem(0, 3);

//         REQUIRE(0);
//     } catch (invalid_argument& e) {}
// }