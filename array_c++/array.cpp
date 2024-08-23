#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int arrayQ(int arr[], int n) {
    
}

int main() {
    int arr[] = {12 ,35 ,1 ,10 ,34 ,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before arr\n";  
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    arrayQ(arr, n);
 
    return 0;
}
