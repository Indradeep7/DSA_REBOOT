#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// bubble sort
// Repeatedly swaps adjacent elements if they are in the wrong order.
// Time Complexity: O(n²)
// Space Complexity: O(1)

// int bubble_sort(int n, int arr[],int base);
// int bubble_sort(int n, int arr[],int base)
// {
//     base--;
//     if (base>0){
//         for (int i = 0; i < n-1; i++)
//         {
//             if(arr[i] > arr[i + 1]) swap(arr[i],arr[i+1]);
//         }
//         return bubble_sort(n,arr,base);
//     }
// }
int i = 0;
void bubble_sort( int n,int arr[]) {
    // Base Case: range == 1.
    i++;
    if (n == 1) return;
    for (int j = 0; j < n - 1; j++) { 
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }

    //Range reduced after recursion:
    bubble_sort(n - 1,arr);
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
    // int b = n;
    // bubble_sort(n, arr,b);
    bubble_sort(n, arr);

    cout << "After Sorting\n";

    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
    cout << endl;

    return 0;
}