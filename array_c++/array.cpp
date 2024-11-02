#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void f(int nums[],int n) {
        for(int i = 0,j = n - 1;i < n,j >= 0; ) {
            if(nums[i] == 0) {
                for(int j = n - 1;j >= 0;){
                    if(nums[j] != 0) {
                        swap(nums[i],nums[j]);
                        j--;
                        continue;
                    }
                    j--;
                }
            }
            i++;            
        }
}

int main() {
    int arr[] = {1,0,1,0,0,1,1,0};
    int n = (sizeof(arr) / sizeof(arr[0]));

    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    f(arr,n);

    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
