#include "tests.h"
#include <filesystem>
#include <string>
#include "database/database.h"

TEST_CASE("Create an empty DB", "[createEmptyDB]") {
    std::string dbName("testDB");

    DatabaseLib::Database db(DatabaseLib::Database::createEmptyDB(dbName));

    //check if the databases folder exists
    REQUIRE(std::filesystem::is_directory("databases"));
    // check if the dbName folder exists
    REQUIRE(std::filesystem::is_directory("databases/" + dbName));
    // check if the folder is empty
    REQUIRE(std::filesystem::is_empty("databases/" + dbName));

    db.destroy();
    REQUIRE(!std::filesystem::is_directory("databases/" + dbName));
}

TEST_CASE("Load an existing empty DB", "[loadDB]") {
    std::string dbName("testDB");
    DatabaseLib::Database db(DatabaseLib::Database::createEmptyDB(dbName));

    DatabaseLib::Database loaded(DatabaseLib::Database::loadDB(dbName));

    // check if the dbName folder exists
    REQUIRE(std::filesystem::is_directory("databases/" + dbName));
    // check if the folder is empty
    REQUIRE(std::filesystem::is_empty("databases/" + dbName));

    db.destroy();
    REQUIRE(!std::filesystem::is_directory("databases/" + dbName));
}