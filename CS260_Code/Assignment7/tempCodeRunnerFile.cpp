/*
Ken Michna
Assignment 7 Hash Table

Takes a key/value pair, runs key through hash function, hash function returns the index key/value will
be stored at in the hash table.

My hash table contains the customer information and pretend vehicle repair history for a pretend national auto dealership.
I am using the phone number as the key, since phone numbers are more unique than names.

Phone Number Gen Works
Insert works
Search works
Remove works

TODO:
Chain

*/

#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "hash_class.h"
#include "a7_funcs.h"

using namespace std;

// Generates a list (vector, but you taught me Python first so it will always be a list to me)
// of however many random phone numbers user desires.
vector<long long> phoneNumGen(int num2gen){
    //Random number gen stuff from stack overflow.
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1,9);

    string numStr = "";
    long long finalNum;
    vector<long long> numberList;
    numberList.reserve(num2gen);

    // For as many times chosen by user (j), generate a random 10 digit number as a string.
    // Then convert string to a long long and add it to a list of phone numbers. Return
    // the list of phone numbers.
    for(int j=0; j<num2gen; j++){
        for(int i=0; i<10; i++){
            numStr.append(to_string(uni(rng)));
        }
        finalNum = stoll(numStr);
        numberList.push_back(finalNum);
        numStr = "";
    }

    return numberList;
}


main(){
    vector<long long> testnum = phoneNumGen(20);
    HashTable testTbl(20);
    ChainHashTable testChain(20);
    for(int i=0; i<20; ++i){
        cout<<testnum[i]<<endl;
    };

    cout<<"Collisions: "<<testTbl.getCollisionCount()<<endl;

    for(int i=0; i<20; ++i){
        testTbl.insert(testnum[i]);
    }

    cout<<"Hash Table After Inserts: "<<endl;
    for(int i=0; i<20; ++i){
        cout<<i<<": "<<testTbl.table.at(i)<<endl;
    }

    cout<<"Collisions: "<<testTbl.getCollisionCount()<<endl;

    cout<<testTbl.remove(testnum[13])<<endl;

    cout<<"Hash Table After Removal: "<<endl;
    for(int i=0; i<20; ++i){
        cout<<i<<": "<<testTbl.table.at(i)<<endl;
    }

    //CHAIN STUFF

    // cout<<"Blank Chain Table: "<<endl;
    // for(int j=0; j<20; ++j){
    //     for(int i=0; i<20; ++i){
    //         cout<<(testChain.chainTable)[j][i]<<endl;
    //     }
    // };

    // for(int i=0; i<20; ++i){
    //     testChain.chainInsert(testnum[i]);
    // };

    // cout<<"Chain Table after inserts: "<<endl;
    // for(int j=0; j<20; ++j){
    //     for(int i=0; i<20; ++i){
    //         cout<<(testChain.chainTable)[j][i]<<endl;
    //     }
    // };    

};