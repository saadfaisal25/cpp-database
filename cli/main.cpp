#include <cxxopts.hpp>
#include <iostream>
#include "mydatabase/mydatabase.h"

using namespace DatabaseLib;

cxxopts::Options options("database-cli", "A command line interface for the database library");

int main(int argc, char* argv[]) {
  options.add_options()
    ("h,help", "Print help")
    ("c,create", "Create a new database")
    ("d,destroy", "Destroy a database")
    ("s,set", "Set a key-value pair")
    ("g,get", "Get a value")
    ("r,remove", "Remove a key")
    ("n,db-name", "Database name (required)", cxxopts::value<string>())
    ("k,key", "Key", cxxopts::value<string>())
    ("v,value", "Value", cxxopts::value<string>())
    ("l,list", "List all keys");

  auto result = options.parse(argc, argv);

  if (result.count("h")) {
    cout << options.help() << endl;
    return 0;
  } 

  if (result.count("c")) {
    if (result.count("n") == 0) {
      cout << "Please provide a database name using -n [name]" << endl;
      return 1;
    }

    string dbName = result["n"].as<string>();
    MyDatabase::createEmptyDB(dbName);
    cout << "Database " << dbName << " created" << endl;
    return 0;
  }

  if (result.count("d")) {
    if (result.count("n") == 0) {
      cout << "Please provide a database name using -n [name]" << endl;
      return 1;
    }

    string dbName = result["n"].as<string>();
    unique_ptr<IDatabase> db(MyDatabase::loadDB(dbName));

    db->destroy();
    cout << "Database " << dbName << " destroyed" << endl;
    return 0;
  }

  if (result.count("s")) {
    if (result.count("n") == 0) {
      cout << "Please provide a database name using -n [name]" << endl;
      return 1;
    }

    if (result.count("k") == 0) {
      cout << "Please provide a key using -k [key]" << endl;
      return 1;
    }

    if (result.count("v") == 0) {
      cout << "Please provide a value using -v [value]" << endl;
      return 1;
    }

    string dbName = result["n"].as<string>();
    string key = result["k"].as<string>();
    string value = result["v"].as<string>();

    unique_ptr<IDatabase> db(MyDatabase::loadDB(dbName));
    db->set(key, value);
    cout << "Key-value pair added" << endl;
    return 0;
  }

  if (result.count("g")) {
    if (result.count("n") == 0) {
      cout << "Please provide a database name using -n [name]" << endl;
      return 1;
    }

    if (result.count("k") == 0) {
      cout << "Please provide a key using -k [key]" << endl;
      return 1;
    }

    string dbName = result["n"].as<string>();
    string key = result["k"].as<string>();

    unique_ptr<IDatabase> db(MyDatabase::loadDB(dbName));
    cout << db->get(key) << endl;
    return 0;
  }

  if (result.count("r")) {
    // TODO
  }

  if (result.count("l")) {
    // TODO
  }

  cout << options.help() << endl;
  return 1;
}