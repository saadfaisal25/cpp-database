#include "tests.h"

#include "mydatabase/mydatabase.h"
#include <string>
#include <iostream>

TEST_CASE("Measuring performance of setting and getting key-value pairs", "[performance][get][set]") {
    std::string dbName("testDB");
    std::unique_ptr<DatabaseLib::IDatabase> db(DatabaseLib::MyDatabase::createEmptyDB(dbName));

    int numberOfPairs = 100000;

    std::cout << "Performance test for " << numberOfPairs << " key-value pairs" << std::endl;
    std::cout << "-------- SET --------" << std::endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (long i=0; i<numberOfPairs; ++i) {
        db->set(std::to_string(i), std::to_string(i));
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Setting " << numberOfPairs << " key-value pairs took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0
              << " seconds" << std::endl;
    std::cout << numberOfPairs / (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /1000000.0)
              << " pairs per second" << std::endl;

    std::cout << "-------- GET --------" << std::endl;
    begin = std::chrono::steady_clock::now();
    for (long i=0; i<numberOfPairs; ++i) {
        db->get(std::to_string(i));
    }
    end = std::chrono::steady_clock::now();

    std::cout << "Getting " << numberOfPairs << " key-value pairs took "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000000.0
              << " seconds" << std::endl;
    std::cout << numberOfPairs / (std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() /1000000.0)
                << " pairs per second" << std::endl;
    
    db->destroy();
}