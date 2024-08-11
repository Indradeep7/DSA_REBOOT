#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// selection__sort

void selection_sort(int n,int arr[]);
void selection_sort(int n,int arr[]) {
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            if(arr[i] > arr[j]) 
                swap(arr[i],arr[j]); // permanent change
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