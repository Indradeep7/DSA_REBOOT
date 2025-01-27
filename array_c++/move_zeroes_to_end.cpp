#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void moveZeroes(vector<int>& nums) {
    int j = 0;
    // move all the nonzero elements advance
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    for (;j < nums.size(); j++) {
        nums[j] = 0;
    }
}

int main() {
    vector<int> nums = {3, 0, 5, 0, 2};

    cout << "Original array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    moveZeroes(nums);

    cout << "Updated array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}