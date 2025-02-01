/* the interpolation search formula is lo + (((x-arr[lo])*(hi-lo))/(arr[hi]-arr[lo]))
    where x = element to be searched
    arr = array which is being searched
    lo = starting index in arr
    hi = ending index in arr
*/
#include <iostream>
#include <vector>
using namespace std;
template <typename T, size_t N>
int interpolationSearch(T (&arr)[N], T toFind, int low, int high){
     if (low > high || toFind < arr[low] || toFind > arr[high]) {
        return -1;
    }

    // Avoid division by zero
    if (arr[high] == arr[low]) {
        if (toFind == arr[low]) {
            return low;
        } else {
            return -1;
        }
    }
    if(low <= high && toFind <= arr[high] && toFind >= arr[low]){
        int pos = low + (((toFind-arr[low])*(high-low))/(arr[high]-arr[low]));
        if(arr[pos] == toFind){
            return pos;
        }
        else if(arr[pos] < toFind){
            return interpolationSearch(arr, toFind, pos+1, high);
        }
        else if(arr[pos] > toFind){
            return interpolationSearch(arr, toFind, low, pos-1);
        }
    }
    return -1;
}

int main(){
    int test[] = {1, 2, 3, 5, 7, 9, 10};
    int lookFor;
    int size = sizeof(test)/sizeof(int);
    printf("What do you want look for?\n");
    scanf("%d", &lookFor); /* This will only work searching for ints and strings, template
    definition would need some form of internal definition of the element/object that is being 
    searched for in the array we pass in. */
    int result = interpolationSearch(test, lookFor, 0, size-1);
    if(result==-1){
        cout << "Could not find " << lookFor << " in the array!" << endl;
    }
    else{
        cout << "Found " << lookFor << " at index " << result << " in the array" << endl;
    }
    return 0;
}
