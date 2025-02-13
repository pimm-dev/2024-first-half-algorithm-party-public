#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int N = inf.readInt(3, 300'000, "N");
    inf.readSpace();
    int Q = inf.readInt(1, 300'000, "Q");
    inf.readEoln();
    
    for(int i = 0; i<N; i++)
    {
        int Ai = inf.readInt(0,63,"Ai");
        if(i == N-1)
            inf.readEoln();
        else
            inf.readSpace();
    }
    
    bool isOne = false;
    while(Q--)
    {
        int t = inf.readInt(1, 2, "t");
        inf.readSpace();
        int l = inf.readInt(1, N, "l");
        inf.readSpace();
        int r = inf.readInt(1, N, "r");
        inf.readSpace();
        int x = inf.readInt(0, 63, "x");
        inf.readEoln();
        ensuref(l <= r, "l < r");
        
        if(t == 1)
            ensuref(r-l+1 >= 3, "invalid range l,r");
        if(t == 1)
            isOne = true;
    }
    inf.readEof();
    ensuref(isOne, "No 1 query!");
    return 0;
}
