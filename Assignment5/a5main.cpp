/*
Ken Michna
CS260
Assignment 5
Program automatically sorts inserted values in a list.
Program can return True/False or the position of a value being searched for.

Unfortunately the inserted value erases the current value at that position because I
lack the skills to make arrays grow and shrink in size as I add and remove values.
BUT...it does put the value in the right spot.
*/

#include <iostream>
#include <array>
#include <sstream>
#include <string>

#include "a5_functions.h"

using namespace std;

int main(){
    int my_array[10];

    //my_array.fill(0);  WHY DOESNT THIS WORK ANYMORE******************
    //only works if I create an array like so -> array<int,10> why? ***********

    fill_array(my_array);
    cout<<"Manually created array prior to inserting values: "<<endl;
    for(int i=0; i<10; i++){
        cout<<my_array[i]<<" ";
    }

    insert_value(10,my_array);
    insert_value(50,my_array);

    //Prints array after values entered.
    cout<<endl<<"Manual array after 10 and 50 inserted: "<<endl;
    for(int i=0; i<10; i++){
        cout<<my_array[i]<<" ";
    }

    //Tests that functions work.
    cout<<endl<<"Bool find result for 10 (should be True/1):  "<< find_inarray(10, my_array, 10) <<endl;
    cout<<"Integer find result:  "<< int_find_inarray(50, my_array, 10) <<endl;


    string str_size;
    int array_size;

    //needs input validation. Don't know how yet.
    cout << endl << "How long is your array?: ";
    getline(cin, str_size);
    array_size = stoi(str_size); //converts string entered into an int


    int *new_array = create_array(array_size);

    cout<<"FOR TEST: SIZE OF DESIRED ARRAY IS - "<< array_size <<endl;

    //print array created by my function to make sure it works.
    cout<<"Array created by create_array function:"<<endl;
    for(int i=0; i<array_size; i++){
        cout<<new_array[i]<<" ";
    }

    //Some tests using couts.
    cout<<endl<<endl<<"Print outs showing outputs of various functions: "<<endl;
    cout<<endl<<"Binary search result for 50 on this array[size "<<array_size<<"] (should be false / 0): "<<endl;
    cout<<binary_find(50, new_array, array_size);
    cout<<endl<<"Binary search result for 36 on this array[size "<<array_size<<"] (should be true / 1): "<<endl;
    cout<<binary_find(36, new_array, array_size);
    cout<<endl<<"Binary search result for middle value of 100 on this array[size "<<array_size<<"] (should be true / 1): "<<endl;
    cout<<binary_find(100, new_array, array_size);

    //A loop to test the binary search yourself.
    int user_value =1;
    while(user_value != 0){
        for(int i=0; i<array_size; i++){
        cout<<new_array[i]<<" ";
        }
        cout<<endl<<endl<<"Enter 0 to EXIT";
        cout<<endl<<"What number would you like to search for in the above array? ";
        cin>>user_value;
        cout<<endl<<"Binary search result of your number: "<<binary_find(user_value, new_array, array_size)<<endl;
    }

    return 0;
}