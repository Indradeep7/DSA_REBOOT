#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber1(vector<int>& a) {
    int N = a.size();
    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N; i++) {
        xor2 ^= a[i]; // XOR of array elements
        xor1 ^= i;    // XOR up to [0...N-1]
    }

    xor1 ^= N; // XOR up to [0...N]

    return (xor1 ^ xor2); // the missing number
}


int missingNumber2(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int sum_index = n;
    int sum_arr = 0;
    while(i < n) {
        sum_index += i;
        sum_arr += nums[i];
        i++;
    }
    return (sum_index - sum_arr);
}

int main() {

    // range [0, n]
    vector<int> nums = {0, 3, 1, 5, 6, 2};

    cout << "Original array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Missing number: " << missingNumber2(nums) << endl;
    return 0;
}