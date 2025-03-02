#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> normalize(int n, int arr[]){
    int max = INT_MIN;
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        max = std::max(arr[i], max);
        min = std::min(arr[i], min);
    }
    return {min, max};
}

vector<int> BucketSort(int n, int arr[]){
    vector<int> res; 
    pair<int, int> minmax = normalize(n, arr);
    vector<vector<int>> buckets(n); // have n buckets for maximum efficiency
    double range = minmax.second-minmax.first;
    for(int i = 0; i < n; i++){
        int normalized_val = static_cast<double>(arr[i])/range; // normalized values produced are in the range (0, 1).
        int bucket_index = min(static_cast<int>(normalized_val * n), n - 1); // determine respective bucket index depending on normalized value scaled up by the total amount of elements that need to be sorted.
        buckets[bucket_index].push_back(arr[i]);
    }
    for (auto bucket : buckets){
        std::sort(bucket.begin(), bucket.end());
        res.insert(res.end(), bucket.begin(), bucket.end());
    }
    return res;
}

int main(){
    int arr[10] = {1,5,6,3,7,2,9,0,10,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    auto answer = BucketSort(n, arr);
    cout << "Sorted all numbers." << endl;
    for (int num : answer){
        cout << num << endl;
    }
    return 0;

}
