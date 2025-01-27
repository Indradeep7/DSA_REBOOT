#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}




int main() {

    vector<int> nums = {4,1,2,1,2};

    cout << "Original array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Single number: " << singleNumber(nums) << endl;
    return 0;
}