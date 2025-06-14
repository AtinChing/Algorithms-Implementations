#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> CountingSort(int n, vector<int> arr, int exp){
    int ma = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > ma) ma = arr[i];
    }
    vector<int> indexArr(ma+1); // this is our index array, stores the amount of occurences of each number (number being the index of that array).
    for(int i = 0; i < n; i++){
        indexArr[(arr[i]/exp)%10]++;
    }
    for(int i = 1; i <= ma; i++){
        indexArr[i] += indexArr[i-1];
    }
    vector<int> sortedArr(n);
    for(int i = n-1; i >= 0; i--){
        sortedArr[indexArr[(arr[i]/exp)%10]-1] = arr[i];
        indexArr[(arr[i]/exp)%10]--;
    }
    return sortedArr;
}

vector<int> RadixSort(int n, vector<int> arr){
    int ma = INT_MIN;
    for(int i = 0; i < n; i++){
        ma = max(arr[i], ma);
    }
    int maxDigits = 0;
    while(ma > 0){
        ma /= 10;
        maxDigits++;
    }
    for(int i = 0; i < maxDigits; i++){
        arr = CountingSort(n, arr, pow(10, i));
    }
    return arr;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = RadixSort(n, vector<int>(arr, arr+n));
    for (int num : answer){
        cout << num << endl;
    }
    return 0;

}
