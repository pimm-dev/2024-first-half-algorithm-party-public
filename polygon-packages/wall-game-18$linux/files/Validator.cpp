#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int n = inf.readInt(2, 1'000'000, "n");
    inf.readEoln();
    string s = inf.readString("[OX.]{"+ to_string(n)+ "}","s");
    ensuref(n == s.size(), "len(s) != n");
    inf.readEof();
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        if(s[i] == 'O')
        {
            int x = 0;
            if(i == 0 || s[i-1] == 'X')
                x++;
            if(i == n-1 || s[i+1] == 'X')
                x++;
            
            ensuref(x < 2, "XOX case");
            cnt++;
        }
    }
    ensuref(cnt == 1, "O is not one");
    return 0;
}
