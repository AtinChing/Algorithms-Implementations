#include <iostream>
#include <cmath>
using namespace std;
int exponentialSearch(int arr[], int arr_size, int target){
    int jumpSize = 1; 
    for(int i = jumpSize; i < arr_size; i+=(arr_size-i-1>=jumpSize ? jumpSize : arr_size-i-1)){
        if(arr[i] == target){
            return i;
        }
        else if (arr[i] > target)
        {
            for(int j = i-jumpSize; j<i; j++){
                if (arr[j] == target){
                    return j;
                }
            }
            break;
        }
        jumpSize *= 2;
    }
    return -1;
}
int main(){
    int search[11] = {1, 3, 5, 6, 10, 15, 16, 20, 21, 24, 29}; 
    int look_for = 29;
    int ans = exponentialSearch(search, 11, look_for);
    cout << "found " << look_for << " at index " << ans; // index -1 means not found
    return 0;
}