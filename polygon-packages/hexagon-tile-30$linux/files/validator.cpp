#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int n = inf.readInt(2, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(2, 1000, "m");
    inf.readSpace();
    int k = inf.readInt(0, n*m-2, "k");
    inf.readEoln();

    set<pair<int,int>> s;
    for(int i = 0;i < k;i++)
    {
      int y = inf.readInt(0, n-1, "y");
      inf.readSpace();
      int x = inf.readInt(0, m-1, "x");

      ensuref(y != 0 || x != 0, "Invalid y,x 0,0");
      ensuref(y != n-1 || x != m-1, "Invalid y,x n-1,m-1");
      ensuref(s.find({y,x}) == s.end(), "y,x twice");

      s.insert({y,x});
      inf.readEoln();
    }

   ensuref(s.size() == k, "wrong k number");
    inf.readEof();
    
    return 0;
}
