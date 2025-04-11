#include <iostream>
#include <vector>
using namespace std;

vector<int> RadixSort(int n, int arr[]){
    vector<int> res(arr, arr + n); 
    return res;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = RadixSort(n, arr);
    for (int num : answer){
        cout << num << endl;
    }
    return 0;

}
