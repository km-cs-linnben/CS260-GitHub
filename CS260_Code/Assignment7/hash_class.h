#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class HashTable {
    public:
        HashTable();
        HashTable(int initial_size);

        bool insert(long long phoneNumber);
        string search(string value);
        bool remove(string value);

        int hash_it(long long phoneNumber);

        int getCapacity();
        int getSize();
        float getFullness();

        int getInsertCount();
        int getCollisionCount();
        vector<string> table;

    private:
        int size;
        int capacity;

        int insertCount;
        int collisionCount;
};

// class ChainHashTable {
//     public:
//         ChainHashTable();
//         ChainHashTable(int initial_size);

//         bool insert(long long phoneNumber);
//         bool chainInsert(long long phoneNumber);
//         string search(string value);
//         bool remove(string value);

//         int hash_it(long long phoneNumber);

//         int getCapacity();
//         int getSize();
//         float getFullness();

//         int getInsertCount();
//         int getCollisionCount();

//     private:
//         vector<vector<string>> chainTable;
//         int size;
//         int capacity;

//         int insertCount;
//         int collisionCount;
// };