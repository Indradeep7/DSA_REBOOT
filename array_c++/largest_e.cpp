#include <iostream>
#include <vector>
using namespace std;

int largest(vector<int>& arr) {
    int max = arr[0]; 
    
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    return max;
}


int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << largest(nums) << endl; // 1

    nums = {2, 1, 3, 4};
    cout << largest(nums) << endl; // 0

    return 0;
}