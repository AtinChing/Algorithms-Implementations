#include <iostream>
#include <cmath>
using namespace std;
int fibSearch(int arr[], int arr_size, int target){
    int optSize = sqrt(arr_size); 
    for(int i = optSize; i < arr_size; i+=(arr_size-i-1>=optSize ? optSize : arr_size-i-1)){
        if(arr[i] == target){
            return i;
        }
        else if (arr[i] > target)
        {
            for(int j = i-optSize; j<i; j++){
                if (arr[j] == target){
                    return j;
                }
            }
            break;
        }
    }
    return -1;
}
int main(){
    int search[11] = {1, 3, 5, 6, 10, 15, 16, 20, 21, 24, 29}; 
    int look_for = 29;
    int ans = fibSearch(search, 11, look_for);
    cout << "found " << look_for << " at index " << ans; // index -1 means not found
    return 0;
}