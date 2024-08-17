#include <iostream>
#include <algorithm> // For swap

using namespace std;

// Function to partition the array around a pivot element
int partition(int A[], int l, int h)
{
    int pivot = A[l]; // Choosing the first element as the pivot
    int i = l, j = h;

    do
    {
        // Increment i until an element greater than pivot is found
        do { i++; } while (A[i] <= pivot);
        // Decrement j until an element less than or equal to pivot is found
        do { j--; } while (A[j] > pivot);

        // Swap elements if i is less than j
        if (i < j) swap(A[i], A[j]);
    } while (i < j);

    // Place the pivot element in its correct position
    swap(A[l], A[j]);
    return j; // Return the index of the pivot
}

// Recursive QuickSort function
void QuickSort(int A[], int l, int h)
{
    if (l < h)
    {
        // Partition the array and get the pivot index
        int p_index = partition(A, l, h);
        // Recursively sort the elements before the pivot
        QuickSort(A, l, p_index);
        // Recursively sort the elements after the pivot
        QuickSort(A, p_index + 1, h);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}; // Array to be sorted
    int n = sizeof(A) / sizeof(A[0]); // Calculate the number of elements in the array

    cout << "Before Sorting\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " "; // Print the array before sorting
    cout << endl;
    cout << endl;

    QuickSort(A, 0, n); // Call QuickSort to sort the array

    cout << "After Sorting\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " "; // Print the array after sorting
    cout << endl;
    cout << endl;

    return 0; // Return success
}
