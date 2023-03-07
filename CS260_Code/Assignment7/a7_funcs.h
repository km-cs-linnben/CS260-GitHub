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
    //cout<<index<<endl;
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

int HashTable::getCollisionCount(){return collisionCount;}


bool HashTable::remove(long long phoneNumber){
    int index = search(phoneNumber);
    if(index != NULL && table.at(index) == to_string(phoneNumber)){
        table.at(index) = "";
        cout<<phoneNumber<<" removed."<<endl;
        return true;
    }
    return false;
}

int HashTable::search(long long phoneNumber){
    int index = hash_it(phoneNumber);
    if (table.at(index) != "" && table.at(index) == to_string(phoneNumber)){
        cout<<phoneNumber<<" found at index: "<<index<<endl;
        return index;
    }
    cout<<phoneNumber<<" not found"<<endl;
    return NULL;
}

// CHAIN TABLE BELOW HERE

ChainHashTable::ChainHashTable() : ChainHashTable(20){}

ChainHashTable::ChainHashTable(int isize){
    chainTable.resize(isize);
    chainSize = isize;
    fill(chainTable.begin(),chainTable.end(), vector<string>(10,""));
    cout<<"done"<<endl;
}

int ChainHashTable::chainGetSize() {return chainSize;}

bool ChainHashTable::chainInsert(long long phoneNumber){
    int index = chain_hash_it(phoneNumber);
    int col = 0;
    while(chainTable[index][col] != ""){
        //cout<<index<<" "<<col<<endl;
        ++col;
    }
    cout<<"STORED AT "<<index<<" "<<col<<endl;
    chainTable[index][col] = to_string(phoneNumber);
    return true;
}

int ChainHashTable::chain_hash_it(long long phoneNumber){
    int index = (phoneNumber / 100000000) % chainGetSize();
    return index;    
}

int ChainHashTable::chainSearch(long long phoneNumber){
    int index = chain_hash_it(phoneNumber);
    int col = 0;
    while(chainTable[index][col] != ""){
        if(chainTable[index][col] != to_string(phoneNumber)){
            ++col;
        }else if(chainTable[index][col] == to_string(phoneNumber)){
            cout<<phoneNumber<<" found at row: "<<index<<" col: "<<col<<endl;
            return index;
        }
    }
    cout<<phoneNumber<<" not found"<<endl;
    return NULL;
}