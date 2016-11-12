#include <iostream>
#include <array>
#include <random>

using namespace std;

int main(){

//declare variables
int size_array; //size of array (ie the number of things the array holds)
int i, j; //counter


// make arrays
int data[8] = {1, 5, 7, 8, 4, 6, 3, 2};

int data_InsSort[8]; // array sorted by insertion sort

int data_Quicksort[8]; // array sorted by quicksort


//get the length of the arrays
size_array = (sizeof(data)/sizeof(*data));


// print the initial array
for( i=0 ; i<8 ; i++) {
cout<<data[i];
}
cout<<"\n";

//Insertion Sort the array
copy(data, data+8, data_InsSort);

for (i=0; i < size_array -1 ; i++){
    if (data_InsSort[i]<data_InsSort[i+1]){
            j=i;
            while (j>0 && data_InsSort[j]<data_InsSort[j-1]){
                swap(data_InsSort[j], data_InsSort[j-1]);
                j--;
            }
    }
}

// print the insertion sorted array
for ( i=0 ; i<8 ; i++){
cout<<data_InsSort[i];
}
cout<<"\n";

//Quick Sort the array

// print the quick sorted array
for ( i=0; i<8; i++){
cout<<"%d, ", i, data_Quicksort[i];
}
cout<<"\n";

return 0;
}
