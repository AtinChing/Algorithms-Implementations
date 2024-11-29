#include <iostream>
#include <vector>
using namespace std;
template <typename T, size_t N>
int binarySearch(T (&arr)[N], T toFind){
    int length = sizeof(arr)/sizeof(int);
    int left = 0;
    int right = length-1; 
    while(left<=right){
        int middle = (left+right)/2;
        if (arr[middle] == toFind){
            return middle;
        }
        else if(arr[middle] > toFind){
            right = middle-1;
        }
        else if(arr[middle] < toFind){
            left = middle+1;
        }
    }
    return -1;
}

int main(){
    int test[] = {1, 2, 3, 4, 5, 6, 10};
    int lookFor;
    cout << "What do you want look for? " << endl;
    scanf("%d", &lookFor); /* This will only work searching for ints and strings, template
    definition would need some form of internal definition of the element/object that is being 
    searched for in the array we pass in. */
    int result = binarySearch(test, lookFor);
    if(result==-1){
        cout << "Could not find " << lookFor << " in the array!" << endl;
    }
    else{
        cout << "Found " << lookFor << " at " << result << " in the array" << endl;
    }
    return 0;
}
