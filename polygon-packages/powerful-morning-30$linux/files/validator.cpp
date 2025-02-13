#include "testlib.h"
#include <bits/stdc++.h>
#include <set>
using namespace std;
set<pair<int,int>> dupl;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int n = inf.readInt(3, 100, "n");
    inf.readSpace();
    int m = inf.readInt(1, n*(n-1), "m");
    inf.readSpace();
    int q = inf.readInt(1, 200'000, "q");
    inf.readEoln();
    
    for(int i = 0; i<m ;i++)
    {
        int s = inf.readInt(1, n, "s");
        inf.readSpace();
        int e = inf.readInt(1, n, "e");
        inf.readSpace();
        int c = inf.readInt(1, 10000, "c");
        inf.readEoln();
        ensuref(s != e, "s == e error");
        ensuref(dupl.find({s,e}) == dupl.end(),"dupl");
        dupl.insert({s,e});
    }
    
    for(int i = 0; i<q; i++)
    {
        int s = inf.readInt(1, n, "se");
        inf.readSpace();
        int k = inf.readInt(1, n, "k");
        inf.readSpace();
        int e = inf.readInt(1, n, "ee");
        inf.readEoln();
        ensuref(s != e, "s == e error");
        ensuref(s != k, "s == k error");
        ensuref(e != k, "e == k error");
    }
    inf.readEof();
    return 0;
}
