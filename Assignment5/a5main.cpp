/*
Ken Michna
CS260
Assignment 5
Program automatically sorts inserted values in a list.
Program can return True/False or the position of a value being searched for.
*/

#include <iostream>
#include <array>
#include <math.h>
#include <sstream>
#include <string>


using namespace std;

void fill_array(int an_array[]){
    for (int i=0; i < 10; i++){
        an_array[i] = pow(i,2);
    }
}

void insert_value(int value, int an_array[]){
    for(int i=0; i<10; i++){
        if(value > an_array[i]){
            continue;
        }else{
            an_array[i-1] = value;
            break;
        }
    }
}

//No idea how this works, I just kept typing stuff until it did what I wanted.
//Ask Joseph why this works*************************
//Creates an array of the specified size. Then fills it with some numbers.
int *create_array(int length){
    int *new_array = new int [length];  // <-specifically this part

    for (int i=0; i < length; i++){
        new_array[i] = pow(i,2);
    }
    return new_array;
}

bool find_inarray(int desired_value, int an_array[], int array_size){

    for(int i = 0; i < array_size; i++){
        if(an_array[i] == desired_value){
            int found_value = an_array[i];
            return true;
            break;
        }
    }
    //if(result == true){} <- why does it not recognize result?********************
}

//Why does this break if I change to a void type function and erase the return line?
int int_find_inarray(int desired_value, int an_array[], int array_size){

    for(int i = 0; i < array_size; i++){
        if(an_array[i] == desired_value){
            int found_value = an_array[i];
            int result = i;
            cout<<desired_value<<" Found at position "<<i<<endl;
            //return result;
        }
    }
}

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
    cout<<endl<<"Bool find result:  "<< find_inarray(10, my_array, 10) <<endl;
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


    return 0;
}