#include <stdio.h>
#include <stdlib.h>


int InsSort();
int Quicksort();

int main(){

//declare variables
int size; //size of array (ie the number of things the array holds)
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
int InsSort(int ages[8], int ages_InsSort[8], int i){

//Step 1: Insert ages[0] into sorting list.  As list is only one item long, consider it sorted.
//Step 2: Insert ages[1] into sorting list.  Compare elements [1] and [0].  If [0]<[1], do nothing.  If [0]>[1], swap the elements.
//Step 3: Insert ages[2] into sorting list.  Compare elements [2] and [1].  If [1]<[2], do nothing.

ages_InsSort[0] = ages[0];

//Now consider ages[1].  Compare with ages[0].
if (ages[1]<ages[0]){
ages_InsSort[0] = ages[1];
ages_InsSort[1] = ages[0];
}
else{
    ages_InsSort[1] = ages[1];
}

//Now consider ages[2].
if (ages[2]<ages_InsSort[1]){
        ages_InsSort[2] = ages_InsSort[1];
    if (ages[2]<ages_InsSort[0]){
        ages_InsSort[1] = ages_InsSort[0];
        ages_InsSort[0] = ages[2];
    }
    else{
        ages_InsSort[1] = ages[2];
    }
}
else{
    ages_InsSort[2] = ages[2];
}

//Now consider ages[3].
if (ages[3]<ages_InsSort[2]){
    ages_InsSort[3] = ages_InsSort[2];
    if (ages[3]<ages_InsSort[1]){
        ages_InsSort[2] = ages_InsSort[1];
        if (ages[3]<ages_InsSort[0]){
            ages_InsSort[1] = ages_InsSort[0]
            ages_InsSort[0] = ages[3];
        }
        else{
            ages_InsSort[1] = ages[3];
        }
    }
    else {
        ages_InsSort[2] = ages[3];
    }
}
else{
    ages_InsSort[3] = ages[3]
}

//Now consider ages[4].
if (ages[4]<ages_InsSort[3]){
    InsSort[4] = InsSort[3];
    if(ages[4]<ages_InsSort[2]){
        ages_InsSort[3] = ages_InsSort[2];
        if (ages[4]<ages_InsSort[1]){
            ages_InsSort[2] = ages_InsSort[1];
            if (ages[4]<ages_InsSort[0]){
                ages_InsSort[1] = ages_InsSort[0];
            }
            else{
                ages_InsSort[1] = ages[4];
            }
        }
        else{
         ages_InsSort[2] = ages[4];   I
        }
    }
    else{
        ages_InsSort[3] = ages[4];
    }
}
else{
    ages_InsSort[4] = ages[4];
}


return 0;
}



// 2. Quicksort function
int Quicksort(){

return 0;
}
