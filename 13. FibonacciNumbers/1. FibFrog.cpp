// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    A.push_back(1); //adding one leave at the end of the vector A because we need  the other border of the river to have a valid position

    //calculate the fibonacci numbers not greater than the size of the river
    vector<float> fib(100,0); //creates a vector of 100 items to store fibonacci number in it. initialized with 0. float type is used for PT in codility
    fib[1]=1;
    for(unsigned int i=2;i<100;i++)
    {
        fib[i]=fib[i-1]+fib[i-2]; //calculates the fibonacci number
        if(fib[i]>A.size()) break; // we do not need a fibonacci number which is greater than the width of the river
    }

    //deleting first two elements of the fibonacci number as they are of no use
    fib.erase(fib.begin()); //erase the first element of fibonacci number as it is 0 (no use), second is 1 that is getting rpeated in third element so erase that also
    fib.erase(fib.begin());

    //vector to store # of steps
    vector<int> numOfStepsReached(A.size(),0); //size we can make max of size of A and intilized all the elements with 0

    //calculates position that can be reached in first jump
    for(unsigned int j=0; j<A.size();j++)
    {
        if(A[fib[j]-1]==1) numOfStepsReached[fib[j]-1]=1; //if value of A at the fibonacci number j minus 1 position is 1, this will set the element at fibonacci position minus one as 1 (as this position can be reached in one fibonacci jump)
    }
    
    //calculates jumps and position that can be reached in second and further jumps
    for(unsigned int i=0; i<A.size();i++)
    {
        //skip places where we do not have leaves as we are not interseted in those, also if we have already filled the ith index value with the fibonacci number in first step we do not have to look into those positions
        if(A[i]==0 || numOfStepsReached[i]>0) continue; 

        int min_i = 1; //minimum position at start
        int min_v  = 100000; //limitated by codility 
        for(unsigned int j=0;j<fib.size();j++) //for each position i, we will check all the fibonacci number 
        {
            int prevIdx = i-fib[j];
            if(prevIdx<0) break; //less than -1, we will jump out since it will not be possible to jump that
            if (numOfStepsReached[prevIdx]>0 && min_v>numOfStepsReached[prevIdx])
            {
                min_v = numOfStepsReached[prevIdx];
                min_i = prevIdx;
            }
        }
            
        if(min_i != -1) numOfStepsReached[i] = min_v+1;
    }

    if(numOfStepsReached[A.size()-1] > 0) return numOfStepsReached[A.size()-1];
    else return -1;    
}
