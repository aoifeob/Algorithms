#include <iostream>
#define ARRAY_LENGTH 8

using namespace std;

int InsSort(int *data, int *data_InsSort){

    //Insertion sort the array

    int InsSortCounter = 0; //counting number of comparisons made

    // i indicates the last item in the "sorted" list, j indicates the latest item to be sorted
    for (int i=1; i < ARRAY_LENGTH; i++){
        //i will go through the list from left to right, starting at index 1
        //we don't need to consider index 0 as one element by itself can be considered sorted
        InsSortCounter++; //the if below compares elements i and i-1
        if (data_InsSort[i]<data_InsSort[i-1]){ //if our current element is greater than the previous element, we need to move our current element
            int j=i; //j and i begin at the same place in each loop iteration
            while (j>0  && data_InsSort[j]<data_InsSort[j-1] ){ //as long as we haven't gone past the start of the list, and the value of our latest item to be sorted is less than the item to its left
                swap(data_InsSort[j-1], data_InsSort[j]); //swaps latest item to be sorted if its value is less than the item to its left
                j--;  //j follows the latest item to be sorted down the "sorted" list
                InsSortCounter++;  //We compare elements j and j-1
                                                            } //end while
                                               } //end if
                                        } //end for

    return InsSortCounter; //return the counter value so we can print it

}

int Subdivide_array (int *data_Quicksort, int A, int Z){
    //we want to subdivide our array so anything less than our pivot is on the left, and anything greater than the pivot is on the right, of the "wall"

    int pivot = data_Quicksort[Z]; //select last element of array as pivot
    int wall = A; // the "wall" that divides elements less than and greater than pivot

    for (int i=A; i<Z; i++){ //go through the array from first to last element
            if (data_Quicksort[i]<=pivot){ //if an array element is less than our chosen pivot
                swap(data_Quicksort[i], data_Quicksort[wall]); //we swap that particular element with the element where our wall is
                wall++; //we move our wall to the right by one
                //QuicksortCount++;  //first comparison
            } //end if
            else{
                    //QuicksortCount++;  // second comparison
            } //end else
    } // end for
    swap(data_Quicksort[Z], data_Quicksort[wall]); //move the pivot into its sorted spot in the array

return wall; //return wall value so we know how to subdivide further
}

int Quicksort(int *data_Quicksort, int A, int Z, int &QuicksortCount){

    //Quicksort the array
    //let A be the start of the array, and Z be the end of the array
    int *p = &QuicksortCount; //pointer to increment the count
    if (A<Z){ //partition until we can't get any smaller
        *p += Z-A; //each time the pivot changes, there will be a number of comparisons equal to the last index minus the first index in the subdivision
        int wall = Subdivide_array(data_Quicksort, A, Z); //subdivide the array
        //recursion to repeat the process until each subdivision only contains one element and is therefore sorted
        Quicksort(data_Quicksort, A, wall-1, QuicksortCount); // repeat process for elements less than the pivot
        Quicksort(data_Quicksort, wall+1, Z, QuicksortCount); // repeat process for elements greater than the pivot
    }
    return *p; // return the counter value so we can print it
}


int main(){
    int A, Z; //A is the first index of our array, Z is the last
    int QuicksortCount = 0; //the counter starts at 0

    // make arrays
    int data[ARRAY_LENGTH] = {1, 6, 2, 8, 4, 5, 3, 7}; //sample data

    int data_InsSort[ARRAY_LENGTH]; // array sorted by insertion sort
    copy(data, data+8, data_InsSort); // copy contents of data array into data_InsSort array

    int data_Quicksort[ARRAY_LENGTH]; //array sorted by quicksort
    copy(data, data+8, data_Quicksort); // copy contents of data array into data_Quicksort array

    // print the initial array
    cout<<"Unsorted list: ";
    for(int i=0 ; i<ARRAY_LENGTH ; i++) {
        cout<<data[i];
    } //end for
    cout<<"\n\n";

    //Insertion sort the array and return the counter value
    int InsSortCounter = InsSort(data, data_InsSort);

    cout<<"Insertion sorted list: ";
    // print the insertion sorted array
    for (int i=0 ; i<ARRAY_LENGTH ; i++){
        cout<<data_InsSort[i];
    } //end for
    cout<<"\n"<<"Number of probes: "<<InsSortCounter<<"\n\n";

    //Quicksort the array and return the counter value
    QuicksortCount = Quicksort(data_Quicksort, 0, ARRAY_LENGTH-1, QuicksortCount);

    cout<<"Quicksorted list: ";
    // print the quicksorted array
    for (int i=0 ; i<ARRAY_LENGTH ; i++){
        cout<<data_Quicksort[i];
    } //end for
    cout<<"\n"<<"Number of probes: "<<QuicksortCount<<"\n\n";

    return 0;
}
