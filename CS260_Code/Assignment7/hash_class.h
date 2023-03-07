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
        int search(long long phoneNumber);
        bool remove(long long phoneNumber);

        int hash_it(long long phoneNumber);

        int getCapacity();
        int getSize();
        float getFullness();

        int getInsertCount();
        int getCollisionCount();
        void resetCollisions();
        vector<string> table;

    private:
        int size;
        int capacity;

        int insertCount;
        int collisionCount =0;
};

class ChainHashTable {
    public:
        ChainHashTable();
        ChainHashTable(int initial_size);

        bool chainInsert(long long phoneNumber);
        string chainsearch(string value);
        bool chainRemove(string value);

        int chain_hash_it(long long phoneNumber);

        // int getCapacity();
        int chainGetSize();
        // float getFullness();

        // int getInsertCount();
        // int getCollisionCount();

        vector<vector<string>> chainTable;

    private:
        int chainSize;
        int chainCapacity;

        int chainInsertCount;
        int chainCollisionCount =0;
};