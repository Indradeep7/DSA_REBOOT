#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// insertion sort
// "Insertion Sort works by picking each element and placing it in the right spot among the elements that are already sorted."
// Time Complexity: O(n²)
// Space Complexity: O(1)
// Best Case: O(n) when the array is already sorted.

static int i = 0;
void insertion_sort(int n, int arr[]);
void insertion_sort(int n, int arr[])
{
    if (n == 0) return;
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) { 
            swap(arr[j-1],arr[j]);
            j--;
        }
    i++;
    insertion_sort(n-1,arr);
}
// void insertion_sort(int arr[], int i, int n) {

//     // Base Case: i == n.
//     if (i == n) return;

//     int j = i;
//     while (j > 0 && arr[j - 1] > arr[j]) {
//         int temp = arr[j - 1];
//         arr[j - 1] = arr[j];
//         arr[j] = temp;
//         j--;
//     }

//     insertion_sort(arr, i + 1, n);
// }

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