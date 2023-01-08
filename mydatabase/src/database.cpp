#include "database.h"
#include "extensions/database-ext.h"

#include <filesystem>
#include <iostream>
#include <fstream>

using namespace DatabaseLib;
using namespace DatabaseExt;

class EmbeddedDatabase::Impl : public IDatabase {
public:
    Impl(const string& dbName);
    ~Impl();

    static const unique_ptr<IDatabase> createEmptyDB(const string& dbName);
    static const unique_ptr<IDatabase> loadDB(const string& dbName);

    void destroy();
    void set(const string& key, const string& value);
    string get(const string& key);

private:
    string dbName;
};

// Implementation

EmbeddedDatabase::Impl::Impl(const string& dbName) : dbName(dbName) {}

EmbeddedDatabase::Impl::~Impl() {}

const unique_ptr<IDatabase> EmbeddedDatabase::Impl::createEmptyDB(const std::string& dbName) {
    string basePath = "databases/";
    if (!filesystem::is_directory(basePath)) {
        filesystem::create_directory(basePath);
    }

    string dbPath = basePath + dbName;
    if (!filesystem::is_directory(dbPath)) {
        filesystem::create_directory(dbPath);
    }

    return make_unique<EmbeddedDatabase::Impl>(dbName);
}

const unique_ptr<IDatabase> EmbeddedDatabase::Impl::loadDB(const string& dbName) {
    return make_unique<EmbeddedDatabase::Impl>(dbName);
}

void EmbeddedDatabase::Impl::destroy() {
    filesystem::remove_all("databases/" + dbName);
}

void EmbeddedDatabase::Impl::set(const string& key, const string& value) {
    ofstream file;
    file.open("databases/" + dbName + "/" + key, ios::out | ios::trunc);
    file << value;
    file.close();
}

string EmbeddedDatabase::Impl::get(const string& key) {
    ifstream file;
    file.open("databases/" + dbName + "/" + key, ios::in);

    string value;
    getline(file, value);
    file.close();

    return value;
}

// Embedded Database

EmbeddedDatabase::EmbeddedDatabase(const string& dbName) : pImpl(make_unique<EmbeddedDatabase::Impl>(dbName)) {}

EmbeddedDatabase::~EmbeddedDatabase() {}

const unique_ptr<IDatabase> EmbeddedDatabase::EmbeddedDatabase::createEmptyDB(const std::string& dbName) {
    return EmbeddedDatabase::Impl::createEmptyDB(dbName);
}

const unique_ptr<IDatabase> EmbeddedDatabase::EmbeddedDatabase::loadDB(const string& dbName) {
    return EmbeddedDatabase::Impl::loadDB(dbName);
}

void EmbeddedDatabase::EmbeddedDatabase::destroy() {
    pImpl->destroy();
}

void EmbeddedDatabase::EmbeddedDatabase::set(const string& key, const string& value) {
    pImpl->set(key, value);
}

string EmbeddedDatabase::EmbeddedDatabase::get(const string& key) {
    return pImpl->get(key);
}                  