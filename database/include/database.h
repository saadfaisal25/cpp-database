#ifndef DATABASE_H
#define DATABASE_H

#include <string>

using namespace std;

namespace DatabaseLib {

class Database
{
public:
    Database(const string& dbName);
    ~Database();

    static Database createEmptyDB(const string& dbName);
    static Database loadDB(const string& dbName);

    void destroy();
    void set(const string& key, const string& value);
    string get(const string& key);

private:
    string dbName;
};

}

#endif // DATABASE_H