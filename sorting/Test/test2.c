#include <stdio.h>

void merge(int arr[],int l,int mid,int h) {

    int i,j,k;
    i = l,j = mid + 1;
    k = l;

    int res[h+1];

    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            res[k++] = arr[i++];  
        }
        else res[k++] = arr[j++];
    }
    
    while (i <= mid)
    {
      res[k++] = arr[i++];  
    } 
    while (j <= h)
    {
      res[k++] = arr[j++];  
    } 

    for(int i = l;i <= h;i++) {
        arr[i] = res[i];
    }   

} 

void merge_sort(int arr[],int l,int h) {
    
    if (l < h)
    {
        int mid = (l + h) / 2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
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