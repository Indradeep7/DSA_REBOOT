#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& nums) {
int n = nums.size();
int count_breaks = 0;

for (int i = 0; i < n; i++) {
    // if curr_e > next_e
    if (nums[i] > nums[(i + 1) % n]) {
        count_breaks++;
        if (count_breaks > 1) {
            cout << "count_breaks = " << count_breaks << endl;
            return false; // More than one break point means it can't be a valid rotated sorted array
        }
    }
}
cout << "count_breaks = " << count_breaks << endl;
return true; // At most one break point, valid rotated sorted array
    
}


int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << check(nums) << endl; // 1

    nums = {2, 1, 3, 4};
    cout << check(nums) << endl; // 0

    return 0;
}