#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to remove duplicates
int removeDuplicates(vector<int>& nums) {
    int count = !nums.empty(); 
    for (int n : nums) {
        if (n != nums[count - 1]) { // Check if the current element is different from the last unique element
            nums[count++] = n;      // Place the unique element at the correct position
        }
    }
    return count; // Return the number of unique elements
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 1, 3}; 

  
    sort(nums.begin(), nums.end());

    cout << "Sorted Array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    int k = removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: \n";
    for (int i = 0; i < k; i++) { 
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
