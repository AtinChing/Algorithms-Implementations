#include <iostream>
#include <vector>
using namespace std;

vector<int> CountingSort(int n, int arr[]){
    int ma = INT_MIN;
    for(int i = 0; i < n; i++){
        ma = max(arr[i], ma);
    }
    vector<int> temp(ma+1);
    for(int i = 0; i < n; i++){
        temp[arr[i]]++;
    }
    for(int i = 1; i <= ma; i++){
        temp[i] += temp[i-1];
    }
    vector<int> sorted_arr(n);
    for(int i = n-1; i >= 0; i--){
        sorted_arr[temp[arr[i]]-1] = arr[i];
        temp[arr[i]]--;
    }
    return sorted_arr;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = CountingSort(n, arr);
    for (int num : answer){
        cout << num << endl;
    }
    return 0;

}
