#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void vector_stl(){
    vector<int> v; // empthy container
    v.push_back(2); // size inc to 1 and 2 is added
    v.emplace_back(2); // size inc to 1 and 2 is added dynamically (faster)
    for (int i : v) cout << i << " ";
    
    vector<pair<int,int>>vec;
    vec.push_back({1,2}); // Difference in syntax
    vec.emplace_back(1,2);

    vector<int> v1(5,40);  // ---> {40,40,40,40,40}
    vector<int> v1(5);  // ---> {0,0,0,0,0} or any garbage value
    
}
int main()
{
    vector_stl();
    return 0;
}