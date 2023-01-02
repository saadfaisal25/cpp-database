#ifndef DATABASE_H
#define DATABASE_H

#include <string>

using namespace std;

class Database
{
public:
    Database(const string& dbName);
    ~Database();

    static Database createEmptyDB(const string& dbName);

protected:
    string dbName;
};

#endif // DATABASE_H