#include <iostream>
using namespace std;

// Function to merge two subarrays into a single sorted array
// A[] is the array, low and high are the bounds of the subarrays
void Merge(int A[], int low, int mid, int high) {
    int i = low;       // Starting index for the left subarray
    int j = mid + 1;   // Starting index for the right subarray
    int k = low;       // Starting index for the merged array
    int B[high + 1];   // Temporary array to store the merged result

    // Merge the two subarrays into array B[]
    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {  // Compare elements from both subarrays
            B[k++] = A[i++]; // Copy smaller element from left subarray
        } else {
            B[k++] = A[j++]; // Copy smaller element from right subarray
        }
    }

    // Copy any remaining elements of the left subarray into B[]
    while (i <= mid) {
        B[k++] = A[i++];
    }

    // Copy any remaining elements of the right subarray into B[]
    while (j <= high) {
        B[k++] = A[j++];
    }

    // Copy the merged elements back into the original array A[]
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

// Function to perform iterative merge sort
void IterativeMergeSort(int A[], int n) {
    int p;  // p represents the size of subarrays being merged, starts with 2 and doubles each iteration

    // Merge subarrays of size 2, 4, 8, ... until p <= n
    for (p = 2; p <= n; p = p * 2) {
        // Merge adjacent subarrays of size p
        for (int i = 0; i + p - 1 < n; i = i + p) {
            int low = i;
            int high = i + p - 1;
            int mid = (low + high) / 2;
            Merge(A, low, mid, high); // Merge the two subarrays
        }
    }

    // Special case: Handle the remaining elements if p/2 < n
    if (p / 2 < n) {
        Merge(A, 0, p / 2 - 1, n - 1); // Final merge for remaining elements
    }
}

int main() {
    int A[] = {13, 46, 24, 20, 52, 20, 9, 10}; // Array with duplicates and even size
    int n = sizeof(A) / sizeof(A[0]);          // Calculate the number of elements in the array

    // Print the array before sorting
    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    // Perform iterative merge sort on the array
    IterativeMergeSort(A, n);

    // Print the array after sorting
    cout << "After Sorting: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
