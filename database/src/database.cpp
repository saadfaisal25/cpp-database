#include "database.h"

#include <string>
#include <filesystem>

using namespace std;

Database::Database(const std::string& dbName) : dbName(dbName) {}

Database::~Database() {}

Database Database::createEmptyDB(const std::string& dbName) {
    string basePath = "databases/";
    if (!filesystem::is_directory(basePath)) {
        filesystem::create_directory(basePath);
    }

    string dbPath = basePath + dbName;
    if (!filesystem::is_directory(dbPath)) {
        filesystem::create_directory(dbPath);
    }

    return Database(dbName);
}