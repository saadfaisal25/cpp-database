#ifndef MYDATABASE_H
#define MYDATABASE_H

#include "database.h"

namespace DatabaseLib {

class MyDatabase {
  public:
    MyDatabase();

    static const unique_ptr<DatabaseLib::IDatabase> createEmptyDB(const string& dbName);
    static const unique_ptr<DatabaseLib::IDatabase> loadDB(const string& dbName);
};

}

#endif // MYDATABASE_H