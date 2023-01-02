#include "database.h"

#include <filesystem>
#include <iostream>
#include <fstream>

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

Database Database::loadDB(const string& dbName) {
    return Database(dbName);
}

void Database::destroy() {
    filesystem::remove_all("databases/" + dbName);
}

void Database::set(const string& key, const string& value) {
    ofstream file;
    file.open("databases/" + dbName + "/" + key, ios::out | ios::trunc);
    file << value;
    file.close();
}

string Database::get(const string& key) {
    ifstream file;
    file.open("databases/" + dbName + "/" + key, ios::in);

    string value;
    getline(file, value);
    file.close();

    return value;
}