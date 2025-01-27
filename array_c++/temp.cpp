#include <iostream>
using namespace std;

class Solution {
public:
    void findUnion(int arr1[], int arr2[], int n, int m) {
        int i = 0, j = 0;

        while (i < n && j < m) {
            // Skip duplicates in arr1
            while (i > 0 && i < n && arr1[i] == arr1[i - 1]) i++;
            // Skip duplicates in arr2
            while (j > 0 && j < m && arr2[j] == arr2[j - 1]) j++;

            if (i < n && j < m) {
                if (arr1[i] < arr2[j]) {
                    cout << arr1[i] << " ";
                    i++;
                } else if (arr1[i] > arr2[j]) {
                    cout << arr2[j] << " ";
                    j++;
                } else {
                    cout << arr1[i] << " ";
                    i++;
                    j++;
                }
            }
        }

        // Print remaining elements of arr1
        while (i < n) {
            if (i == 0 || arr1[i] != arr1[i - 1]) {
                cout << arr1[i] << " ";
            }
            i++;
        }

        // Print remaining elements of arr2
        while (j < m) {
            if (j == 0 || arr2[j] != arr2[j - 1]) {
                cout << arr2[j] << " ";
            }
            j++;
        }

        cout << endl;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        int arr1[N], arr2[M];

        for (int i = 0; i < N; i++) {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> arr2[i];
        }

        Solution ob;
        ob.findUnion(arr1, arr2, N, M);
    }

    return 0;
}
