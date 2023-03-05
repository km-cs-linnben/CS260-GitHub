#pragma once
#include <math.h>
#include <iostream>
#include "hash_class.h"

using namespace std;

// Next 3 functions taken from Joseph. Simple enough that redesign doesnt
// seem needed. After reading online I would have done getFullness the same way.

//Helper function to fetch current capacity
int HashTable::getCapacity() {return capacity;}
//Helper function to fetch current size
int HashTable::getSize() {return size;}
//Helper function to fetch current "fullness"
float HashTable::getFullness() {
    int cap = getCapacity();
    float result = 0.0f;
    if(cap != 0) {
        result = (float)size / (float)cap;
    } else {
        result = -1;
    }
    return result;
}

//My Functions from here.

HashTable::HashTable() : HashTable(20){}

// Create a hashtable of whatever size user desires.
HashTable::HashTable(int isize){
    table.reserve(isize);
    size = isize;
    table.assign(isize,"");
}

// Hash Function
int HashTable::hash_it(long long phoneNumber){
    int index = (phoneNumber / 100000000) % getSize();
    cout<<index<<endl;
    return index;
}

bool HashTable::insert(long long phoneNumber){
    int index = hash_it(phoneNumber);
    if(table.at(index) != ""){
        ++collisionCount;
    }
    table.at(index) = to_string(phoneNumber);
    return true;
}

// bool ChainHashTable::chainInsert(long long phoneNumber){
//     int index = hash_it(phoneNumber);
//     int col = 0;
//     while(chainTable[index][col] != ""){
//         col++;
//     }
//     chainTable[index][col] = to_string(phoneNumber);
//     col=0;
//     return true;
// }

// string search(string value){}

// bool remove(string value){}