#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(int n, int arr[]){
    vector<int> res(arr, arr + n); 
    for(int i = 0; i < n; i++){
        int j = i-1;
        int to = res[i];
        while(j >= 0 && res[j] > to){
            res[j+1] = res[j];
            j--;
        }
        res[j+1] = to;
    }
    return res;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = InsertionSort(n, arr);
    cout << "Sorted all numbers." << endl;
    for (int num : answer){
        cout << num << endl;
    }
    return 0;

}
