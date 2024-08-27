#include <iostream>
#include <algorithm>

using namespace std;

void f(int nums[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        // Move i forward until we find a 0
        while (i < j && nums[i] != 0) i++;
        // Move j backward until we find a non-zero element
        while (i < j && nums[j] == 0) j--;
        // Swap the elements at i and j
        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }
}

int main() {
    int arr[] = {1, 0, 1, 0, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    f(arr, n);

    cout << "After:  ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
