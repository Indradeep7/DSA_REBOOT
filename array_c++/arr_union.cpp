#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    vector<int> unionArr;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (unionArr.empty() || unionArr.back() != arr1[i])
                unionArr.push_back(arr1[i]);
            i++;
        } else if (arr1[i] > arr2[j]) {
            if (unionArr.empty() || unionArr.back() != arr2[j])
                unionArr.push_back(arr2[j]);
            j++;
        } else {
            if (unionArr.empty() || unionArr.back() != arr1[i])
                unionArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i < n) {
        if (unionArr.empty() || unionArr.back() != arr1[i])
            unionArr.push_back(arr1[i]);
        i++;
    }

    while (j < m) {
        if (unionArr.empty() || unionArr.back() != arr2[j])
            unionArr.push_back(arr2[j]);
        j++;
    }

    return unionArr;
}

int main() {
    vector<int> vec1 = {1, 2, 4, 5, 6};
    vector<int> vec2 = {2, 3, 5, 7};

    int arr1[vec1.size()];
    int arr2[vec2.size()];

    copy(vec1.begin(), vec1.end(), arr1);
    copy(vec2.begin(), vec2.end(), arr2);

    vector<int> nums = findUnion(arr1, arr2, vec1.size(), vec2.size());

    cout << "Array 1: ";
    for (int i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    cout << "Array 2: ";
    for (int i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    cout << endl;

    cout << "Union array: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}