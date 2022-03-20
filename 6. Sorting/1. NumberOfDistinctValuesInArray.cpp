// you can use includes, for example:
// #include <algorithm>
#include<unordered_set> //std::unordered_set is defined in header <unordered_set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_set<int> s{A.begin(),A.end()};//Unordered set is an associative container that contains a set of unique objects of type Key.
    return s.size();
}
