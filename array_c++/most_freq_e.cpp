//most frequent in an array
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"no of elements:"<<endl;
    cin>>n;

    int arr[n],i,j;
    cout<<"enter the elements:"<<endl;
    for(i = 0; i < n; i++){
        cin>>arr[i];
    }


    int maxcount=-1,key;
    for(i = 0; i < n; i++){
        int cnt = 1;
        for(j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }
        if(cnt>maxcount){
            maxcount = cnt;
            key = arr[i];
        }
    }

    cout<<"the most frequent element is "<<key<<endl;
    
}