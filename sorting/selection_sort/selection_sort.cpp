#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// selection sort
// Selects the smallest (or largest) element from the unsorted part and swaps it with the first unsorted element.
// Time Complexity: O(n²)
// Space Complexity: O(1)

void selection_sort(int n,int arr[]);
void selection_sort(int n,int arr[]) {

    for (int i = 0; i < n - 1; i++)
    {
        int min_i = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_i])
                min_i = j;
        }

        swap(arr[i],arr[min_i]); // permanent change
    }

}


int main()
{

    int arr[] = {13,46,24,52,20,9};
    int n = (sizeof(arr)/sizeof(arr[0]));

    cout << "Before Sorting\n";

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    selection_sort(n,arr);

    cout << "After Sorting\n";

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    

    
    return 0;
}