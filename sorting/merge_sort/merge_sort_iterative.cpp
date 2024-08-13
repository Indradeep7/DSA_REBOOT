#include <iostream>
using namespace std;

// Perform iterative merge sort by progressively merging adjacent subarrays of increasing size, starting from size 2, using a temporary array for merging and then copying back the results to the original array.


void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int B[100]; // Assuming the size of the array is <= 100, adjust if necessary.

    // Merge the two subarrays into array B[]
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {    // sort condition
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    // Copy any remaining elements of the left subarray
    for (; i <= mid; i++) {
        B[k++] = A[i];
    }

    // Copy any remaining elements of the right subarray
    for (; j <= h; j++) {
        B[k++] = A[j];
    }

    // Copy the merged elements back into the original array A[]
    for (i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

void IterativeMergeSort(int A[], int n) {
    int p, i, low, mid, high;

    // For p = 2, 4, 8, ... until p <= n
    for (p = 2; p <= n; p = p * 2) {
        for (i = 0; i + p - 1 < n; i = i + p) {
            low = i;
            high = i + p - 1;
            mid = (low + high) / 2;
            Merge(A, low, mid, high);
        }

        // Merging remaining elements if any
        if (p / 2 < n) {
            Merge(A, 0, p / 2 - 1, n - 1);
        }
    }

    // Special case to handle when p is greater than n
    if (p / 2 < n) {
        Merge(A, 0, p / 2 - 1, n - 1);
    }
}

int main() {
    int A[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    IterativeMergeSort(A, n);

    cout << "After Sorting: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
