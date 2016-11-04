#include <stdio.h>
#include <stdlib.h>


int InsSort();
int Quicksort();

int main(){

//declare variables
int size; //size of array (ie the number of things the array holds)
int ages[8]; // array of test data to be sorted
int i; //counter
int ages_InsSort[8]; // array sorted by insertion sort
int ages_Quicksort[8]; // array sorted by quicksort

// make an array
int ages[8] = {1, 5, 7, 8, 4, 6, 3, 2};

// print the initial array
for( i=0 ; i<8 ; i++) {
printf("%d\n", i, ages[i]);
}

// insertion sort the array
ages_InsSort[8] = InsSort(ages[8]);

// print the insertion sorted array
for ( i=0 ; i<8 ; i++){
printf("%d\n", i, ages_InsSort[i]);
}

// quicksort the array
ages_Quicksort[8] = Quicksort(ages[8]);

// print the quicksorted array
for ( i=0; i<8; i++){
printf("%d\n", i, ages_Quicksort[i]);
}

return 0;
}


// 1. Insertion Sort function
int InsSort(){

return 0;
}


// 2. Quicksort function
int Quicksort(){

return 0;
}
