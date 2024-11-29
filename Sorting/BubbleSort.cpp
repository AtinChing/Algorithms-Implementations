#include <iostream>
#include <vector>
using namespace std;

vector<int> BubbleSort(int n, int arr[]){
    vector<int> res(arr, arr + n); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(res[j] > res[j+1]){
                int temp = res[j];
                res[j] = res[j+1];
                res[j+1] = temp;
            }
        }
    }
    return res;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = BubbleSort(n, arr);
    for (int num : answer){
        cout << num << endl;
    }
    return 0;

}
