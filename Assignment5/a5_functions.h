#include <math.h>
#include <iostream>

using namespace std;

//Fills an array automatically so I don't have to.
void fill_array(int an_array[]){
    for (int i=0; i < 10; i++){
        an_array[i] = pow(i,2);
    }
}

//Inserts value in numerical order compared to values already in array.
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

//Creates an array of the specified size. Then fills it with some numbers.
int *create_array(int length){
    int *new_array = new int [length]; // new always creates a POINTER to an array of size[length]

    for (int i=0; i < length; i++){
        new_array[i] = pow(i,2);
    }
    return new_array;
}

//Simple value search. Searchs an array. Returns True or False
bool find_inarray(int desired_value, int an_array[], int array_size){

    for(int i = 0; i < array_size; i++){
        if(an_array[i] == desired_value){
            int found_value = an_array[i];
            return true;
        }
    }
    return false;
}

//Simple search. Searchs an array. Returns the value if found and what position it was found in.
int int_find_inarray(int desired_value, int an_array[], int array_size){

    int bigO_count = 0;
    for(int i = 0; i < array_size; i++){
        ++bigO_count;
        if(an_array[i] == desired_value){
            int found_value = an_array[i];
            cout<<desired_value<<" Found at position "<<i<<endl;
            cout<<"BigO count: "<<bigO_count<<endl;
            return an_array[i];
        }
    }
    return -1;
}

//More efficient binary search. Returns True/False and, if found, couts the position the value was found in.
bool binary_find(int desired_value, int an_array[], int array_size){
    int low = 0;
    int high = array_size;
    int bigO_count = 0;
    while(low <= high){
        int mid = (low+high)/2;
        if(an_array[mid] == desired_value){
            ++bigO_count;
            cout<<an_array[mid]<<" Found at position "<<mid<<endl;
            cout<<"BigO count: "<<bigO_count<<endl;
            return true;
        }else if(an_array[low] == desired_value || an_array[high-1] == desired_value){
            ++bigO_count;
            cout<<desired_value<<" Found at end or beginning of array"<<endl; //This could be better, keeping it simple for now.
            cout<<"BigO count: "<<bigO_count<<endl;
            return true;            
        }else if(an_array[mid] < desired_value){
            ++bigO_count;
            low = mid + 1;
        }else{
            ++bigO_count;
            high = mid - 1;
        }
    }
    cout<<desired_value<<" Not Found "<<endl;
    cout<<"BigO count: "<<bigO_count<<endl;
    return false;
}