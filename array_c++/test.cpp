#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to remove duplicates
int removeDuplicates(vector<int>& nums) {
    int count = !nums.empty(); // Initialize count to 1 if nums is not empty
    for (int n : nums) {
        if (n != nums[count - 1]) { // Check if the current element is different from the last unique element
            nums[count++] = n;      // Place the unique element at the correct position
        }
    }
    return count; // Return the number of unique elements
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 1, 3}; // Input array

    // Step 1: Sort the array to make duplicates adjacent
    sort(nums.begin(), nums.end());

    // Display the sorted array before removing duplicates
    cout << "Sorted Array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // Step 2: Remove duplicates and get the count of unique elements
    int k = removeDuplicates(nums);

    // Step 3: Display the updated array and count
    cout << "Number of unique elements: " << k << endl;
    cout << "Array after removing duplicates: \n";
    for (int i = 0; i < k; i++) { // Only display the first k elements
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
