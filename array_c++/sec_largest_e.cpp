#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function returns the second
// largest elements
int print2largest(vector<int> &arr) {
    
    int n = arr.size();
    if (n < 2) {
        return -1; // Not enough elements to find the second largest
    }

    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) {
        return -1; // All elements are the same
    }

    return secondLargest;
}


int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << print2largest(nums) << endl; // 1

    nums = {2, 1, 3, 4};
    cout << print2largest(nums) << endl; // 0

    return 0;
}