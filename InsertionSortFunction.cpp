#include <iostream>
#define ARRAY_LENGTH 8

using namespace std;

int InsSort(int *data, int *data_InsSort){

    //Insertion sort the array
    // i indicates the last item in the "sorted" list, j indicates the latest item to be sorted
    for (int i=1; i < ARRAY_LENGTH; i++){ //i will go through the list from left to right
        if (data_InsSort[i]<data_InsSort[i-1]){
            int j=i; //j and i begin at the same place in each loop iteration
            while (j>0 && data_InsSort[j]<data_InsSort[j-1]){ //as long as we haven't gone past the start of the list, and the value of our latest item to be sorted is less than the item to its left
                swap(data_InsSort[j-1], data_InsSort[j]); //swaps latest item to be sorted if its value is less than the item to its left
                j--;  //j follows the latest item to be sorted down the "sorted" list
                                                            }
                                              }
                                    }

    return 0;

}


int main(){

    // make arrays
    int data[ARRAY_LENGTH] = {1, 6, 2, 8, 4, 5, 3, 7};

    int data_InsSort[ARRAY_LENGTH]; // array sorted by insertion sort
    copy(data, data+8, data_InsSort);

    // print the initial array
    for(int i=0 ; i<ARRAY_LENGTH ; i++) {
        cout<<data[i];
    }
    cout<<"\n";

   // cout<<"We're not crashing before the function. \n";
    InsSort(data, data_InsSort);
    //cout<<"We're not crashing after the function. \n";


    // print the insertion sorted array
    for (int i=0 ; i<ARRAY_LENGTH ; i++){
        cout<<data_InsSort[i];
    }
    cout<<"\n";

    return 0;
}
