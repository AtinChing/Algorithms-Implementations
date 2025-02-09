#include <iostream>
#include <vector>
using namespace std;

vector<int> MergeSort(int n, int arr[], int low, int high){
    vector<int> res(arr+low, arr+high);
    if(high-low == 1){    
        return res;
    }
    else if(high-low == 2){
        if(res[0] > res[1]){
            int temp = res[0];
            res[0] = res[1];
            res[1] = temp;
        }
        return res;
    }
    int mid = (low+high)/2;
    vector<int> arr1(arr+low, arr+mid);
    vector<int> arr2(arr+mid+1, arr+high);
    vector<int> temp;
    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = MergeSort(n, arr, 0, n-1);
    cout << "Sorted all numbers." << endl;
    for (int num : answer){
        cout << num << endl;
    }
    return 0;

}
