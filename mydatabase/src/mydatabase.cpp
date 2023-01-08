#include "mydatabase.h"
#include "extensions/database-ext.h"

using namespace DatabaseLib;
using namespace DatabaseExt;

MyDatabase::MyDatabase() {}

const unique_ptr<IDatabase> MyDatabase::createEmptyDB(const string& dbName) {
    return EmbeddedDatabase::createEmptyDB(dbName);
}

const unique_ptr<IDatabase> MyDatabase::loadDB(const string& dbName) {
    return EmbeddedDatabase::loadDB(dbName);
}