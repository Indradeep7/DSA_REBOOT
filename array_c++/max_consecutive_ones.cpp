#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int i = 0,max = 0;
    int count = 0;              
    while(i < n) {
        if(nums[i] != 0) {
            count++;
        }
        else if(max < count) {
            max = count;
            count = 0;
        }
        else count = 0;
        i++;
    }
    if(max < count) max = count;
    return max;
}

int main() {

  
    vector<int> nums = {1,0,1,1,0,1};

    cout << "Original array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "max consecutive ones: " << findMaxConsecutiveOnes(nums) << endl;
    return 0;
}