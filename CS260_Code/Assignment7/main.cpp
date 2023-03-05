/*
Ken Michna
Assignment 7 Hash Table

Takes a key/value pair, runs key through hash function, hash function returns the index key/value will
be stored at in the hash table.

My hash table contains the customer information and pretend vehicle repair history for a pretend national auto dealership.
I am using the phone number as the key, since phone numbers are more unique than names.

Phone Number Gen Works

TODO:
Insert
Search
Remove
Chain

*/

#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "hash_class.h"

using namespace std;

vector<long long> phoneNumGen(int num2gen){
    //Random number gen stuff from stack overflow
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1,9);

    string numStr = "";
    long long finalNum;
    vector<long long> numberList;
    numberList.reserve(num2gen);

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
    vector<long long> testnum = phoneNumGen(6);
    cout<<testnum[0]<<endl;
    cout<<testnum[1]<<endl;
    cout<<testnum[2]<<endl;


}