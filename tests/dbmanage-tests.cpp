#include "tests.h"
#include <filesystem>
#include <string>
#include "database.h"

TEST_CASE("Create an empty DB", "[createEmptyDB]") {
    std::string dbName("testDB");

    Database db(Database::createEmptyDB(dbName));

    //check if the databases folder exists
    REQUIRE(std::filesystem::is_directory("databases"));
    // check if the dbName folder exists
    REQUIRE(std::filesystem::is_directory("databases/" + dbName));
    // check if the folder is empty
    REQUIRE(std::filesystem::is_empty("databases/" + dbName));
}