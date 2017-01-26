#include <iostream>

using namespace std;

void SelectionSort(int *data, int *data_sorted){
    for (int i=1; i<=7; i++){
        int min = i;
        for (int j=i+1; j<=8; j++){
            if (data_sorted[j]<data_sorted[min]){
               min =j;
            }
        }
        if (min != i){
            swap(data_sorted[i], data_sorted[min]);
        }
    }
}

int main(){
    // array to be sorted
    int data[8] = {5, 3, 2, 7, 6, 1, 8, 4};

    //array to store sorted list
    int data_sorted[8];
    copy(data, data+8, data_sorted);

    //print unsorted array
    cout<<"Unsorted list: ";
    for(int i=0 ; i<8 ; i++) {
        cout<<data[i];
    } //end for
    cout<<"\n\n";

    //sort the array
    SelectionSort(data, data_sorted);

    //print sorted array
    cout<<"Sorted list: ";
    for(int i=0 ; i<8 ; i++) {
        cout<<data_sorted[i];
    } //end for
    cout<<"\n\n";

    return 0;
}
