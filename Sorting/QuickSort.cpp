#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int partition(int arr[], int lower, int upper){
    int pivotElem = arr[upper];
    int i = lower;
    for(int j = lower; j <= upper; j++){
        if(arr[j] < pivotElem){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[upper]);
    return i;
}

int* quickSort(int arr[], double lower = 0, double upper = -1){
    if(lower < upper){
        int pivotIndex = partition(arr, lower, upper);
        quickSort(arr, lower, pivotIndex-1);
        quickSort(arr, pivotIndex+1, upper);
    }
    return arr;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = quickSort(arr, 0, n-1);
    cout << "Sorted all numbers." << endl;
    for(int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }
    return 0;

}
