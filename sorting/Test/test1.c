#include <stdio.h>

void merge(int arr[], int l, int m, int h)
{

    int i, j, k;
    int res[h + 1];

    i = l, j = m + 1, k = l;

    while (i <= m && j <= h)
    {
        if (arr[i] < arr[j])
        {
            res[k++] = arr[i++];
        }
        else
        {
            res[k++] = arr[j++];
        }
    }
    // remaining elements
    while (i <= m)
    {
        res[k++] = arr[i++];
    }
    while (j <= h)
    {
        res[k++] = arr[j++];
    }
    // merged elements back to OG Array
    for (int i = l; i <= h; i++)
    {
        arr[i] = res[i];
    }
}

void merge_sort(int arr[], int l, int h)
{

    if (l < h)
    {
        int m = (l + h) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

int main()
{

    int A[] = {13, 46, 24, 20, 52, 20, 9};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Before Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    merge_sort(A, 0, n - 1);

    printf("After Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}