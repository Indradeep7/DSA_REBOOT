#include<stdio.h>
 void heapify(int arr[],int n, int i){
   int largest=i;
   int left = 2*i;
   int right = 2*i +1;
    
      if(left<= n && arr[left]>arr[largest]){
         largest=left;
      }
      if(right<= n && arr[right] > arr[largest]){
        largest=right;
      }
       if(largest !=i){
        int temp= arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        heapify(arr,n,largest);
       }
     
    
 }

 void heap(int arr[],int s){
    int n =s;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    while(n>1){
        int temp = arr[n];
        arr[n]= arr[1];
        arr[1]= temp;
        n--;
        heapify(arr,n,1);
    }
 }

 int main(){
    int arr[100];
    int size;
    scanf("%d",&size);
    for(int i=1;i<=size;i++){
        scanf("%d",&arr[i]);

    }
    heap(arr,size);
    printf("______________\n");
for(int i=1;i<=size;i++){
    printf("%d\n",arr[i]);
}
 }