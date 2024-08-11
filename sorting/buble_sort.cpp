#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// selection sort
// Repeatedly swaps adjacent elements if they are in the wrong order.
// Time Complexity: O(n²)
// Space Complexity: O(1)

void bubble_sort(int n, int arr[]);
void bubble_sort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
            if(arr[j] > arr[j + 1]) swap(arr[j], arr[j+1]);
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

    bubble_sort(n, arr);

    cout << "After Sorting\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    return 0;
}