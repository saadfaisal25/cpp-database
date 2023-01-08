#ifndef DATABASE_EXT_H
#define DATABASE_EXT_H

#include "../database.h"

namespace DatabaseExt {

using namespace DatabaseLib;

class EmbeddedDatabase : public IDatabase
{
public:
    EmbeddedDatabase(const string& dbName);
    ~EmbeddedDatabase();

    static const unique_ptr<IDatabase> createEmptyDB(const string& dbName);
    static const unique_ptr<IDatabase> loadDB(const string& dbName);

    void destroy();
    void set(const string& key, const string& value);
    string get(const string& key);

    class Impl;

private:
    unique_ptr<Impl> pImpl;
};

}

#endif // DATABASE_EXT_H