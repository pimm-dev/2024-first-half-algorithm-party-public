#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int N = inf.readInt(2, 200'000, "N");
    inf.readSpace();
    int Q = inf.readInt(1, 200'000, "Q");
    inf.readEoln();
    
    for(int i = 0; i<N; i++)
    {
        int Ai = inf.readInt(1,1e9,"Ai");
        if(i == N-1)
            inf.readEoln();
        else
            inf.readSpace();
    }
    
    bool isThree = false;
    while(Q--)
    {
        int t = inf.readInt(1, 3, "t");
        inf.readSpace();
        if(t == 3)
        {
            int a = inf.readInt(1, N, "a");
            inf.readSpace();
            int b = inf.readInt(1, N, "b");
            ensuref(a <= b, "a > b!");
            isThree = true;
        }
        else
        {
            int k = inf.readInt(1,N,"k");
        }
        inf.readEoln();
    }
    inf.readEof();
    ensuref(isThree, "No 3 query!");
    return 0;
}
