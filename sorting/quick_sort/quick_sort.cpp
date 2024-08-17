// #include <iostream>
// #include <algorithm>
// using namespace std;

// int partition(int A[],int l,int h)  
// {  
//     int pivot=A[l];  
//     int i=l,j=h;  
//     do  
//     {  
//         do{i++;}while(A[i]<=pivot);  
//         do{j--;}while(A[j]>pivot);  
//     }while(i<j);  
//     if(i<=j)swap(A[i],A[j]);  
//     swap(A[l],A[j]);  
//     return j;  
// }
// void QuickSort(int A[],int l,int h)  
// {  
//     int j;  
//     if(l<h)  
//     {  
//         j=partition(A,l,h);  
//         QuickSort(A,l,j);  
//         QuickSort(A,j+1,h);  
//     }  
// }  
// int main()  
// {  
//     int A[]={11,13,7,12,16,9,24,5,10,3,INT32_MAX},n=11,i;  
//     QuickSort(A,0,n-1);  
//     for(i=0;i<10;i++)  
//         printf("%d ",A[i]);  
//     printf("\n");  
//     return 0;  
// }  

#include <iostream>
#include <algorithm> // For swap

using namespace std;

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do{i++;} while (A[i] <= pivot);
        do{j--; } while (A[j] > pivot);

        if (i < j)swap(A[i], A[j]);
    } while (i < j);

    swap(A[l], A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Before Sorting\n";

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << endl;

    QuickSort(A, 0, n);

    cout << "After Sorting\n";

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    cout << endl;

    return 0;
}
