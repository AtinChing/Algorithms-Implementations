#include <iostream>
using namespace std;
int fibSearch(int arr[], int arr_size, int target){
    int fibO = 1;
    int fib1 = 1;
    int fib2 = 0;
    int offset = -1;
    while(fibO < arr_size){
        fib2 = fib1;
        fib1 = fibO;
        fibO = fib2+fib1;//5, 3, 2
    }
    while(fibO>1){
        // for debugging: cout << fibO << " " << fib1 << " " << fib2 << " " << offset << endl;
        int i = offset+fib2;
        if(arr[i] == target){
            return i;
        }
        else if(arr[i]>target){ // remove 2 thirds of array to the right of element 
            fibO = fib2;
            fib1-=fibO;
            fib2 = fibO-fib1;
        }
        else if(arr[i] < target){ // remove first 1 third of array
            offset = i;
            fibO = fib1;
            fib1 = fib2;
            fib2 = fibO-fib1;
        }
    }
    if(arr[arr_size-1] == target){ // by default, the core fibonacci search algorithm is incapable of scanning the absolute last element of the array, so we must do a hard coded check like this.
        return arr_size-1;
    }
    return -1;
}

int main(){
    int search[5] = {1, 3, 5, 6, 10}; 
    int look_for = 10;
    int ans = fibSearch(search, 5, look_for);
    cout << "found " << look_for << " at index " << ans; // index -1 means not found
    return 0;
}