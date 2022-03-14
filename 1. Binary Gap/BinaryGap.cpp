// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
#include<vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    //store binary result in vector of type int
    vector<int> v;

    //converts the integer to binary
    while(N>0)
    {
        v.push_back(N%2); //push the modulus of each division in vector v as long as numver N is positive
        N/=2;
    }
    //iteration1: N=7, 7%2=1, N=3
    //iteration1: N=3, 3%2=1, N=1
    //iteration1: N=1, 1%2=1, N=0
    //binary will be reverse of the above order:111 (from down to top)

    //countMax will hold the max value of count reached
    int count = 0, countMax = 0;
    for(int i=v.size()-1; i>=0; i--) //v.size()-1 gives the index of the last number present in vector
    {
        if(v[i]==0) count++;//0 counter
        else if(v[i]==1) {countMax = std::max(countMax,count); count=0;} 
        //countMax stores maximum value of gap between previous and next 1 or previous gap if that is more
        //reset the counter when you see a binary 1.
        //
    }
    return countMax;

}
