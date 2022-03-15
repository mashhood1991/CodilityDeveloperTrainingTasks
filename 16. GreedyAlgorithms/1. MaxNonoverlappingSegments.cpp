// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
        int len = A.size(); //get size of vector A
    if(len==0) return 0; //if vector A is empty, them there will be no overlap
    int count =1;
    vector<int> lastElementCmp = vector<int>(len, -1); //lastElementCmp is a vector of size of A with all the elements are initilized to -1
    for(int i=1;i<len;++i)
    {
        if ((A[i] > B[i-1]) || (-1 != lastElementCmp[i-1] && A[i]>lastElementCmp[i-1])) //in first lopp it checks if A[2]>B[1] or A[2]>lastElementCmp[1] that needs to be compared to check if the vector is having lowrr value than A.
        ++count;
        else
         lastElementCmp[i] = -1 != lastElementCmp[i-1] ? lastElementCmp[i-1]:B[i-1];
    }
    return count;
}
