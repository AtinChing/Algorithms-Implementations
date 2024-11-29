#include <iostream>
#include <vector>
using namespace std;
template <typename T, size_t N>
int linearSearch(T (&arr)[N], T toFind){
    int length = sizeof(arr)/sizeof(int);
    for(int i = 0; i<N; i++){
        if(arr[i] == toFind){
            return i;
        }
    }
    return -1;
}

int main(){
    int test[] = {4, 2, 3, 1, 5, 6, 3, 2, 10};
    int lookFor;
    printf("What do you want look for?");
    scanf("%d", &lookFor); /* This will only work searching for ints and strings, template
    definition would need some form of internal definition of the element/object that is being 
    searched for in the array we pass in. */
    int result = linearSearch(test, lookFor);
    if(result==-1){
        cout << "Could not find " << lookFor << " in the array!" << endl;
    }
    else{
        cout << "Found " << lookFor << " at " << result << " in the array" << endl;
    }
    return 0;
}
