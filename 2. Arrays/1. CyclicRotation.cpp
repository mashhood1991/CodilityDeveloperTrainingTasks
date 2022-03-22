// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) { //here input argument is capital K
    // write your code in C++14 (g++ 6.2.0)

    //calculate size of array to initialize B and it can be used in looping over the array A 
    int arrSize = A.size(); //also remember A.size() returns unsigned int

    //we cannot use A to store the rotated elements (then A will be changed and in next cycle of the for-loop A will not be the same as the initial A)
    //vector to store the rotated elements
    vector<int> B(arrSize); 
    for(int i=0; i<arrSize; i++)
    {
        B[(i+K) % arrSize] = A[i]; /ith element position after K right rotation will be (i+K) % arrSize
    }
    return B;
}
