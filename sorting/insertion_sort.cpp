#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// insertion sort
// "Insertion Sort works by picking each element and placing it in the right spot among the elements that are already sorted."
// Time Complexity: O(n²)
// Space Complexity: O(1)
// Best Case: O(n) when the array is already sorted.

void insertion_sort(int n, int arr[]);
void insertion_sort(int n, int arr[])
{
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) { // if previous ele is > current ele then swap and do the same for all where now prev ele is the curr ele now.... check till j > 0...if not true then don't check further
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}

int main()
{

    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = (sizeof(arr) / sizeof(arr[0]));

    cout << "Before Sorting\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    insertion_sort(n, arr);

    cout << "After Sorting\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    return 0;
}