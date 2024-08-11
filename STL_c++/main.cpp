#include <iostream>
// #include <utility> // for std::pair
// #include <bits/stdc++.h>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>

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

void prac_list() {
    //same as vector 
    //extra: gives us front operations as well

    list <int> ls;
    ls.push_back(1); // {1}
    ls.emplace_back(2); // {1,2}

    ls.push_front(5); // {5,1,2} //replacement of insert in vector
    // insert takes lot of time ...costly
    // vector : dynamic array || list : Doubly LL  
    
    ls.emplace_front(); // {0,1,2}
    for(auto it : ls) cout << it << " ";
    cout<<endl;

}

void prac_stack() {
    stack<int> st1;
    st1.push(1); // {1}
    st1.push(2); // {1,2}
    st1.push(3); // {1,2,3}
    st1.push(4); // {1,2,3,4}
    st1.push(5); // {1,2,3,4,5}

    cout<<st1.top()<<endl;

    st1.pop();

    cout<<st1.size()<<endl;

    cout<<st1.empty()<<endl;

    stack<int> st2;
    st1.swap(st2);

    cout<<st1.empty()<<endl;

    swap(st1,st2);

    cout<<st1.empty()<<endl;
}

void prac_queue() {
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1,2}
    q.emplace(4); // {1,2,4}

    q.back() += 5; // 5 + 4

    cout << q.back() << endl; // 9

    q.pop(); // 1 is popped {2,9}

    cout << q.front() <<endl; // 2
}

void prac_priority_queue() {

    // For max heap
    priority_queue<int> pq1;
    pq1.push(5); // {5}
    pq1.push(2); // {5,2}
    pq1.push(8); // {8,5,2}
    pq1.emplace(10); // {10,8,5,2}

    cout << pq1.top() << endl; // 10
    pq1.pop(); // 10 is popped
    cout << pq1.top() << endl; //8
cout << "_______________________________________________\n";
    // For min heap
    priority_queue<int,vector<int>,greater<int>> pq2;
    pq2.push(5); // {5}
    pq2.push(2); // {2,5}
    pq2.push(8); // {2,5,8}
    pq2.emplace(10); // {2,5,8,10}

    cout << pq2.top() << endl; // 2
    pq2.pop(); // 2 is popped
    cout << pq2.top() << endl; //5

    
}

void prac_set() {
    // sorted
    // unique
    // sets don't  have contigous memory
    set<int> s;
    s.insert(1); // {1}
    s.emplace(2); // {1,2}
    s.insert(2); // {1,2}
    s.insert(4); // {1,2,4}
    s.insert(3); // {1,2,3,4}

    auto it1 = s.find(2); // returns an itrator which points to 2 
    // if 2 is not there the it returns s.end() i.e. the last element
    auto it2 = s.find(83277); 
    auto it3 = s.find(4); 

    cout << *(it1) << endl; // 2
    cout << *(it2) << endl; // 4
    cout << *(it3) << endl; // 4

    cout<< s.count(2) << endl;
    cout<< s.count(9) << endl;

    for(auto it : s) cout << it << " ";
    cout<<endl;

    s.erase(it1,it3); // .erase(start_element,end_element); // end_ele excluded

    for(auto it : s) cout << it << " ";
    cout<<endl;

    // auto it = s.lower_bound(2);
    // auto it = s.upper_bound(3);
}
void prac_multi_set() {
    // sorted
    // not unique
    multiset<int> ms;
    ms.insert(1); // {1}
    ms.emplace(2); // {1,2}
    ms.insert(2); // {1,2,2}
    ms.insert(2); // {1,2,2,2}
    ms.insert(4); // {1,2,2,2,4}
    ms.insert(3); // {1,2,2,2,3,4}

    auto it1 = ms.find(2); 
    auto it2 = ms.find(4); 

    cout << *(it1) << endl; // 2
    cout << *(it2) << endl; // 4

    // cout<< ms.count(2) << endl;
    // cout<< ms.count(9) << endl;

    for(auto it : ms) cout << it << " ";
    cout<<endl;
    // {1,2,2,2,3,4}

    // ms.erase(2); // it erases all 2s // {1,3,4}

    // ms.erase(it1); // erases only one 2 //{1,2,2,3,4}


    // advance(it1,2); //it points two step ahead of the ele 2
    // ms.erase(ms.find(2),it1); // erases two 2s

    ms.erase(ms.find(2), next(ms.find(2), 2)); // another way to advance

    for(auto it : ms) cout << it << " ";
    cout<<endl;

    // auto it = ms.lower_bound(2);
    // auto it = ms.upper_bound(3);
}

void prac_unordered_set() {
      
    unordered_set<int> st;  
    // not sorted
    // unique
    
    // lower_bound and upper_bound function  
    // does not works, rest all functions are same  
    // as above, it does not stores in any  
    // particular order it has a better complexity  
    // than set in most cases, except some when collision happens  

}
int main() {
    // prac_pair();
    // prac_vector();
    // prac_list();
    // prac_stack();
    // prac_queue();
    // prac_priority_queue();
    // prac_set();
    // prac_multi_set();
    prac_unordered_set();
    return 0;
}
