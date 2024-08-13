#include <iostream>
using namespace std;

void Merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = 0;
    int temp[h - l + 1]; // Temporary array to store merged array

    // Merge the two halves into temp[]
    while (i <= mid && j <= h) {
        if (A[i] <= A[j]) {
            temp[k++] = A[i++];
        } else {
            temp[k++] = A[j++];
        }
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mid) {
        temp[k++] = A[i++];
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= h) {
        temp[k++] = A[j++];
    }

    // Copy the merged elements back into the original array
    for (i = l, k = 0; i <= h; i++, k++) {
        A[i] = temp[k];
    }
}

void Merge_Sort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;

        // Recursively sort the first half
        Merge_Sort(A, l, mid);

        // Recursively sort the second half
        Merge_Sort(A, mid + 1, h);

        // Merge the two halves
        Merge(A, l, mid, h);
    }
}

int main() {
    int A[] = {13, 46, 24, 20, 52, 20, 9};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    Merge_Sort(A,0,n - 1);

    cout << "After Sorting: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
