#include <stdio.h>


void swap(int *a,int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int l,int h) {
    int i,j;
    int pivot = arr[l];
    i = l;
    j = h;

    do
    {
        do {i++;}while(arr[i] <= pivot);
        do {j--;}while(arr[j] > pivot);
        if (i < j)
        {   
            swap(&arr[i],&arr[j]);
        }
        
    } while (i < j);
    swap(&arr[l],&arr[j]);
    return j;
}

void quick_sort(int arr[],int l,int h) {
    if (l < h)
    {
        int pivot_index = partition(arr,l,h);
        quick_sort(arr,l,pivot_index);
        quick_sort(arr,pivot_index + 1,h);
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

    

    quick_sort(A,0,n);



    printf("After Sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}