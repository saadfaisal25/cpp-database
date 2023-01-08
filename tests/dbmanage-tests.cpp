#include "tests.h"
#include <filesystem>
#include <string>
#include "mydatabase/mydatabase.h"

TEST_CASE("Create an empty DB", "[createEmptyDB]") {
    std::string dbName("testDB");

    std::unique_ptr<DatabaseLib::IDatabase> db(DatabaseLib::MyDatabase::createEmptyDB(dbName));

    //check if the databases folder exists
    REQUIRE(std::filesystem::is_directory("databases"));
    // check if the dbName folder exists
    REQUIRE(std::filesystem::is_directory("databases/" + dbName));
    // check if the folder is empty
    REQUIRE(std::filesystem::is_empty("databases/" + dbName));

    db->destroy();
    REQUIRE(!std::filesystem::is_directory("databases/" + dbName));
}

TEST_CASE("Load an existing empty DB", "[loadDB]") {
    std::string dbName("testDB");
    std::unique_ptr<DatabaseLib::IDatabase> db(DatabaseLib::MyDatabase::createEmptyDB(dbName));

    std::unique_ptr<DatabaseLib::IDatabase> loaded(DatabaseLib::MyDatabase::loadDB(dbName));

    // check if the dbName folder exists
    REQUIRE(std::filesystem::is_directory("databases/" + dbName));
    // check if the folder is empty
    REQUIRE(std::filesystem::is_empty("databases/" + dbName));

    db->destroy();
    REQUIRE(!std::filesystem::is_directory("databases/" + dbName));
}