#include <iostream>
#define ARRAY_LENGTH 8

using namespace std;

int InsSort(int *data, int *data_InsSort){

    //Insertion sort the array

    int InsSortCounter = 0; //counting number of comparisons made

    // i indicates the last item in the "sorted" list, j indicates the latest item to be sorted
    for (int i=1; i < ARRAY_LENGTH; i++){ //i will go through the list from left to right
        if (data_InsSort[i]<data_InsSort[i-1]){ //if our current element is greater than the previous element, we need to move our current element
            int j=i; //j and i begin at the same place in each loop iteration
            InsSortCounter++; //First comparison
            while (j>0  && data_InsSort[j]<data_InsSort[j-1] ){ //as long as we haven't gone past the start of the list, and the value of our latest item to be sorted is less than the item to its left
                swap(data_InsSort[j-1], data_InsSort[j]); //swaps latest item to be sorted if its value is less than the item to its left
                j--;  //j follows the latest item to be sorted down the "sorted" list
                InsSortCounter++;  //Second comparison
                                                            } //end while
                                               } //end if
        else{
            InsSortCounter++; //Third comparison
        }
                                        } //end for

    return InsSortCounter;

}

int Subdivide_array (int *data_Quicksort, int A, int Z, int QuicksortCount){
    //we want to subdivide our array so anything less than our pivot is on the left, and anything greater than the pivot is on the right, of the "wall"

    int pivot = data_Quicksort[Z]; //select last element of array as pivot
    int wall = A; // the "wall" that divides elements less than and greater than pivot

    for (int i=A; i<Z; i++){ //go through the array
            if (data_Quicksort[i]<=pivot){ //if an array element is less than our chosen pivot
                swap(data_Quicksort[i], data_Quicksort[wall]); //we swap that particular element with the element where our wall is
                wall++; //we move our wall to the right by one
                QuicksortCount++;  //first comparison
            } //end if
            else{
                    QuicksortCount++;  // second comparison
            } //end else
    } // end for
    swap(data_Quicksort[Z], data_Quicksort[wall]); //move the pivot into its sorted spot in the array

return wall;
}


// tested making a counting function but it messed up the sorting
/*int Counter (int *data_Quicksort, int false_A, int false_Z, int QuicksortCount){
   //repeating part of our Subdivide function to return QuicksortCount, a highly inefficient implementation
    int false_pivot = data_Quicksort[false_Z];
    //int false_wall = A;

    for (int i=false_A; i<false_Z; i++){
            if (data_Quicksort[i]=false_pivot){
                QuicksortCount++;
            } //end if
            else{
                QuicksortCount++;
            } //end else

    } // end for

return QuicksortCount;
}*/

int Quicksort(int *data_Quicksort, int A, int Z, int QuicksortCount){

    //Quicksort the array

    //let A be the start of the array, and Z be the end of the array
    int false_A = A;
    int false_Z = Z;
    if (A<Z){ //subdivide and sort until we get individual segments
        int wall = Subdivide_array(data_Quicksort, A, Z, QuicksortCount); //subdivide the array
        //int QuicksortCount = Counter(data_Quicksort, false_A, false_Z, QuicksortCount); this method messes up the sorting
        
        //recursion to repeat the process until each subdivision is one element long and is therefore sorted
        Quicksort(data_Quicksort, A, wall-1, QuicksortCount); // repeat process for elements less than the pivot
        Quicksort(data_Quicksort, wall+1, Z, QuicksortCount); // repeat process for elements greater than the pivot
    }
    return QuicksortCount;
}


int main(){
    int A, Z;
    int QuicksortCount= 0;

    // make arrays
    int data[ARRAY_LENGTH] = {1, 6, 2, 8, 4, 5, 3, 7};

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

    int InsSortCounter = InsSort(data, data_InsSort);

    cout<<"Insertion sorted list: ";
    // print the insertion sorted array
    for (int i=0 ; i<ARRAY_LENGTH ; i++){
        cout<<data_InsSort[i];
    } //end for
    cout<<"\n"<<"Number of probes: "<<InsSortCounter<<"\n\n";

    QuicksortCount = Quicksort(data_Quicksort, 0, ARRAY_LENGTH-1, QuicksortCount);
    
    cout<<"Quicksorted list: ";
    // print the quicksorted array
    for (int i=0 ; i<ARRAY_LENGTH ; i++){
        cout<<data_Quicksort[i];
    } //end for
    cout<<"\n"<<"Number of probes: "<<QuicksortCount<<"\n\n";

    return 0;
}
