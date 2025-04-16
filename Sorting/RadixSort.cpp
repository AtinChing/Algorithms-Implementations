#include <iostream>
#include <vector>
using namespace std;

vector<int> CountingSort(int n, vector<pair<int, int>> arr){
    int ma = INT_MIN;
    for(int i = 0; i < n; i++){
        ma = max(arr[i].first, ma);
    }
    vector<int> temp(ma+1);
    for(int i = 0; i < n; i++){
        temp[arr[i].first]++;
    }
    for(int i = 1; i <= ma; i++){
        temp[i] += temp[i-1];
    }
    vector<pair<int, int>> sorted_arr(n);
    for(int i = n-1; i >= 0; i--){
        sorted_arr[temp[arr[i].first]-1] = arr[i];
        temp[arr[i].first]--;
    }
    vector<int> res;
    for(auto pairVals : sorted_arr){
        res.push_back(pairVals.second);
    }
    return res;
}

vector<int> RadixSort(int n, vector<int> arr){
    int ma = INT_MIN;
    for(int i = 0; i < n; i++){
        ma = max(arr[i], ma);
    }
    int place = 0;
    while(ma != 0){
        ma/=10;
        place++;
        vector<pair<int,int>> pairs;
        for(int i : arr){
            int temp = i;
            for(int j = 0; j<place;j++){
                temp/=10;
            }
            pairs.push_back({temp%10, i});
            
        }
        arr = CountingSort(n, pairs);
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
