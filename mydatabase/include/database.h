#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <memory>

using namespace std;

namespace DatabaseLib {

class IDatabase
{
public:
    IDatabase() = default;
    virtual ~IDatabase() = default;

    static const unique_ptr<IDatabase> createEmptyDB(const string& dbName);
    static const unique_ptr<IDatabase> loadDB(const string& dbName);

    virtual void destroy() = 0;
    virtual void set(const string& key, const string& value) = 0;
    virtual string get(const string& key) = 0;
};

}

#endif // DATABASE_H