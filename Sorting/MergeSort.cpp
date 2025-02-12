#include <iostream>
#include <vector>
using namespace std;

vector<int> Merge(vector<int> left_arr, vector<int> right_arr){
    vector<int> res;
    int left, right = 0;
    int leftlen = left_arr.size();
    int rightlen = right_arr.size();
    while(left < leftlen && right < rightlen){
        if(left_arr[left] <= right_arr[right]){
            res.push_back(left_arr[left]);
            left++;
        }
        else{
            res.push_back(right_arr[right]);
            right++;
        }
    }
    while(left != leftlen){
        res.push_back(left_arr[left]);
        left++;
    }
    while(right != rightlen){
        res.push_back(right_arr[right]);
        right++;
    }
    return res;
}

vector<int> MergeSort(int n, int arr[], int low, int high){
    vector<int> res(arr+low, arr+high);
    int len = high-low+1;
    if(len == 1){
        auto ret = vector<int>(arr+low, arr+high+1); 
        return ret;
    }
    int mid = (low+high)/2;

    vector<int> arr1 = MergeSort(n, arr, low, mid);
    vector<int> arr2 = MergeSort(n, arr, mid+1, high);
    
    //arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return Merge(arr1, arr2);
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
