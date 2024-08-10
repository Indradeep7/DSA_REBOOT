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

    // we can push or emplace one element/pair at a time acc to the vector datatype 
    v2.push_back({1,2}); 
    v2.emplace_back(3,4); // It automatically assumes 3,4 to be a pair and inserts it into the array

    vector<int> v3(5,100); // container of size 5 of 5 instances of 100 is initialized {100,100,100,100,100}

    vector<int> v4(5); // container of size 5 is declared

    vector<int> v5(v3); // v5 is another container which is a copy of v3

    cout << v1[0] << " " << v1[1] << endl; // access by index
    cout << v1.at(0) << " " << v1.at(1) << endl; // access by at() func
    cout << v2[0].first << " " << v2[0].second << endl;

    vector <int> :: iterator it1 = v1.begin(); // begin() points directly to the memory of v1 i.e the address of the first element of v1

    cout << *(it1) << " "; // it has the address of v1 and by adding * we are accessing the value at that address

    it1++; // vectors have contigious memory storage

    cout << *(it1) << " ";

    vector<int> :: iterator it2 = v1.end(); // points to the location after the last element of vector therefore we need to do it1-- for accessing the last element
    it2--;
    cout << *(it2);

    vector<int> :: reverse_iterator it3 = v1.rend(); 
    // it3--;
    // cout << *(it3) << endl;

    // cout << v1.back() << " ";

    int x = 5;
    auto y  = 5; // automatically assigns datatype acc to the value initialized

    for (vector<int>:: iterator it = v1.begin(); it != v1.end(); it++)
    {
        // cout << *(it) << " ";
    }
    cout<<endl;
    for (auto it = v1.begin(); it != v1.end(); it++)    cout << *(it) << " ";
    cout<<endl;
    v1.emplace_back(8);
    v1.emplace_back(9);
    v1.emplace_back(5);

    cout<<v1.front(); //gives first element
    cout<<endl;

    cout<<v1.back(); //gives last element
    cout<<endl;

    for (auto it = v1.begin(); it != v1.end(); it++)    cout << *(it) << " ";
    cout<<endl;

    // it means (it) in v1
    for(auto it : v1) cout << it << " "; // another way to print all 
    cout<<endl;

    // v1 = 1 2 8 9 5
    v1.erase(v1.begin() + 1,v1.begin() + 3); // .erase(start, end);

    // v1 = 1 9 5 
    for(auto it : v1) cout << it << " ";  // 2,8 erased 

    cout<<endl;

    v1.insert(v1.begin() + 1,7);
    // v1 = 1 7 9 5
    for(auto it : v1) cout << it << " ";  

    cout<<endl;

    v1.insert(v1.begin() + 1,2,5);
    // insert 2 ele at given pos...
    //two 5s are inserted

    // v1 = 1 5 5 7 9 5 
    for(auto it : v1) cout << it << " ";  

    cout<<endl;

    vector<int> v6(2,69);

    // v1 = 69 69 1 5 5 7 9 5 
    v1.insert(v1.begin(),v6.begin(),v6.end());
    
    for(auto it : v1) cout << it << " ";  

    cout<<endl;
    cout << v1.size(); // size of vector
    cout<<endl;    

    cout<<endl;
    v1.pop_back(); // pops out the last ele of vector
    cout<<endl;    

    // for(auto it : v1) cout << it << " ";  
    // cout<<endl;

    v1.swap(v3); // need to be of same datatype to get swaped

    v1.clear(); // erases all ele of vector
    
    cout << v1.empty(); // checks if vector is empty then returns true(1)else false(0)
    


}

int main() {
    // prac_pair();
    prac_vector();
    
    return 0;
}
