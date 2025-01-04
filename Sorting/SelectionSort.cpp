#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectionSort(int n, int arr[]){
    vector<int> res(arr, arr + n); 
    for(int i = 0; i < n; i++){
        int minNum = res[i];
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if (res[j] < minNum){
                minNum = res[j];
                minIndex = j;
            }
        }
        res[minIndex] = res[i];
        res[i] = minNum;
    }
    return res;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = SelectionSort(n, arr);
    cout << "Sorted all numbers." << endl;
    for (int num : answer){
        cout << num << endl;
    }
    return 0;

}
