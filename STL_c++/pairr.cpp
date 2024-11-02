#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void pair_stl(){
    pair<int,int> p1 = {1,3};
    cout << p1.first << " " << p1.second<<"\n";

    pair<int,pair<int,int>> p2 = {1,{3,4}};
    cout << p2.first << " " <<p2.second.second <<" "<<p2.second.first;

    pair<int,int> arr[] = {{1,2},{2,5},{3,4}};
}
int main()
{
    pair_stl();
    
    return 0;
}