#include <bits/stdc++.h>
using namespace std;

// Longest Subarray with given Sum K(Positives)

int lenOfLongSubarr(int A[],  int N, int K) 
{ 
    // Complete the function
    int i = 0;
    int j = i,sum = 0,max_count = 0,count = 0;
    while(j < N) {
        
        sum += A[j];
        j++,count++;
        
        if(sum > K) {
            sum -= A[i];
            i++,count--;
        }
        
        if(sum == K && count > max_count) {
            max_count = count;
        }
        
    }
    return max_count;
} 

	
int main() 
{ 
    // +ve element case only
    int A[] = {4,1,1,1,2,3,5};
    int N = sizeof(A)/sizeof(A[0]);
    int K = 5;
    cout << "Longest Subsequence with the sum " << K << " is " << lenOfLongSubarr(A, N, K) << endl;
    return 0; 
} 

	