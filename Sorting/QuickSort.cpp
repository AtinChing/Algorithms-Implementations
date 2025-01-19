#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int* QuickSort(int n, int arr[], double lower = 0, double upper = -1){
    if(lower == upper || upper == -1){
        return arr;
    }
    int pivot = std::round(((upper-lower)+1.0)/2.0);
    int j = 0;
    int copiedArray[n];
    int pivotElem = arr[pivot];
    for(int i = 0; i < n; i++) {
        copiedArray[i] = arr[i];
    }
    for(int i = lower; i <= upper; i++){
        if(arr[i]<pivotElem){
            copiedArray[j] = arr[i];
            j++;
        }
    }
    copiedArray[j] = pivotElem;
    int newpivot = j;
    j++;
    for(int i = lower; i <= upper; i++){
        if(arr[i]>=pivotElem && i != pivot){
            copiedArray[j] = arr[i];
            j++;
        }
    }
    arr = copiedArray;
    if(lower != upper){
        int temp = newpivot+1;
        arr = QuickSort(n, arr, lower, newpivot-1);
        cout << temp << endl;
        
        arr = QuickSort(n, arr, temp, upper);
    }
    return arr;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = QuickSort(n, arr, 0, n-1);
    cout << "Sorted all numbers." << endl;
    for(int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }
    return 0;

}
