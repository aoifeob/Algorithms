#include <iostream>
#include <array>

using namespace std;

int main(){

//declare variables
int size_array; //size of array (ie the number of things the array holds)
int i, j; //counter


// make arrays
int data[8] = {1, 6, 2, 8, 4, 5, 3, 7};

int data_InsSort[8]; // array sorted by insertion sort


//get the length of the arrays
size_array = (sizeof(data)/sizeof(*data));


// print the initial array
for( i=0 ; i<size_array ; i++) {
cout<<data[i];
}
cout<<"\n";

//copy the contents of the data array into the data_InsSort array
copy(data, data+8, data_InsSort);


//Insertion sort the array
// i indicates the last item in the "sorted" list, j indicates the latest item to be sorted
for (i=0; i < size_array; i++){ //i will go through the list from left to right
    if (data_InsSort[i]<data_InsSort[i-1]){
            j=i; //j and i begin at the same place in each loop iteration
            while (j>0 && data_InsSort[j]<data_InsSort[j-1]){ //as long as we haven't gone past the start of the list, and the value of our latest item to be sorted is less than the item to its left
                swap(data_InsSort[j-1], data_InsSort[j]); //swaps latest item to be sorted if its value is less than the item to its left
                j--;  //j follows the latest item to be sorted down the "sorted" list
            }
    }
}

// print the insertion sorted array
for ( i=0 ; i<size_array ; i++){
cout<<data_InsSort[i];
}
cout<<"\n";
    
return 0;
}
