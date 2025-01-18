#include <iostream>
#include <vector>
using namespace std;

int* QuickSort(int n, int arr[], int lower = 0, int upper = -1){
    if(lower == upper){
        return arr;
    }
    if(upper == -1){
        upper = n-1;
    }
    int pivot = ((upper-lower)+2)/2;
    int j = lower;
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
    auto answer = QuickSort(n, arr);
    cout << "Sorted all numbers." << endl;
    for(int i = 0; i < n; i++) {
        cout << answer[i] << endl;
    }
    return 0;

}
