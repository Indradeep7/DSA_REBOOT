#include <iostream>
// #include <utility> // for std::pair
// #include <bits/stdc++.h>
#include <vector>
using namespace std;
void prac_pair() {

    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << endl;

    pair<int, pair<int, int>> p2 = {1,{3,4}};
    cout << p2.second.first << " " << p2.second.second << endl;

    pair<int, int> arr[] = {{1,2},{3,4},{5,6}};
}

void prac_vector() {
    // arr are constant in size hence we can't 
    // modify the size of an arr once specified
    // directly... We need to inc it mannualy

    // vectors are dynamic in nature ...
    // Can inc size as per requirement

    vector<int> v1; // crates an empty container {}
    v1.push_back(1); //{1}
    v1.emplace_back(2); //{1,2} dynamically inc the size to add 2

    // both are same .. emplace is faster

    vector<pair<int,int>> v2;
    v2.push_back({1,2});
    v2.emplace_back(3,4); // It automatically assumes 3,4 to be a pair and inserts it into the array

    vector<int> v3(5,100); // container of size 5 of 5 instances of 100 is initialized {100,100,100,100,100}

    vector<int> v4(5); // container of size 5 is declared

    vector<int> v5(v3); // v5 is another container which is a copy of v3

    // cout << v1[0] << " " << v1[1] << endl; // access by index
    // cout << v1.at(0) << " " << v1.at(1) << endl; // access by at() func
    // cout << v2[0].first << " " << v2[0].second << endl;

    vector <int> :: iterator it = v1.begin(); // begin() points directly to the memory of v1 i.e the address of the first element of v1

    cout << *(it) << " "; // it has the address of v1 and by adding * we are accessing the value at that address

    it++; // vectors have contigious memory storage

    cout << *(it) << " ";

    vector<int> :: iterator it1 = v1.end(); // points to the location after the last element of vector therefore we need to do it1-- for accessing the last element
    it1--;
    cout << *(it1);

}

int main() {
    // prac_pair();
    prac_vector();
    
    return 0;
}
