#include <iostream>
#include <vector>
using namespace std;
template <typename T, size_t N>
int ternarySearch(T (&arr)[], T toFind){
    int length = sizeof(arr)/sizeof(T);
    int mid1 = (length/3);
    int mid2 = (length/3)*2;
    int l = 0;
    int r = length-1;
    while(mid1<=mid2){
        if (arr[mid1] == toFind){
            return mid1;
        }
        if (arr[mid2] == toFind){
            return mid2;
        }
        else if(arr[mid2] < toFind){
            mid2++;
            int diff = length-1-mid2;
            int old = mid2;
            int mid1 = old + (diff/3);
            int mid2 = old + (diff/3)*2; 
        }
        else if(arr[mid1] > toFind){
            mid1--;
            int diff = length-1-mid1;
            int old = mid1;
            int mid1 = old + (diff/3);
            int mid2 = old + (diff/3)*2;
        }
        else{ // if num we want to find is in between
            mid2--;
            mid1++;
            int diff = mid2-mid1;
            int old = mid1;
            int mid1 = old + (diff/3);
            int mid2 = old + (diff/3)*2; 
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
    int result = ternarySearch(test, lookFor);
    if(result==-1){
        cout << "Could not find " << lookFor << " in the array!" << endl;
    }
    else{
        cout << "Found " << lookFor << " at " << result << " in the array" << endl;
    }
    return 0;
}
