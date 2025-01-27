#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // In case k > n
    vector<int> tarr(n);
    for(int i = 0; i < n; i++) {
        tarr[(i + k) % n] = nums[i];
    }
    nums = tarr;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    int s = 3;

    cout << "Original array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    rotate(nums, s);

    cout << "Rotated array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}