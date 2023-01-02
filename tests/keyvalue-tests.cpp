#include "tests.h"

#include "database.h"
#include <string>
#include <filesystem>

TEST_CASE("Add and get value", "[set][get]") {
    std::string dbName("testDB");
    Database db(Database::createEmptyDB(dbName));

    // add a key-value pair and check if the added value is the same as the returned value
    std::string key("test-key");
    std::string value("test-value");
    db.set(key, value);
    REQUIRE(db.get(key) == value);

    db.destroy();
    REQUIRE(!std::filesystem::is_directory("databases/" + dbName));
}