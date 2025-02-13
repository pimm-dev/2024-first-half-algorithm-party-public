#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv){
    registerValidation(argc, argv);
    
    int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    int m = inf.readInt(1, 1000, "m");
    inf.readEoln();
    set<string> ss;
    for(int i = 0;i < n;i++)
    {
      int t = inf.readInt(1, 30, "t");
      inf.readSpace();
      string s = inf.readWord();
      inf.readSpace();
      ss.insert(s);
      
      ensuref(s.length()==t, "Invalid slength");
      
      for(int j = 0;j < t;j++)
      {
          ensuref(isalpha(s[j]), "Invalid alphabet");
      }
 
      for(int j = 0;j < 7;j++)
      {
          char k = inf.readChar();
          ensuref('A' <= k &&'G' >= k, "Invalid character k");
          if(j != 6)
            inf.readSpace();
          else
            inf.readEoln();
      }
    }
    
    for(int i = 0;i < m;i++)
	{
	    for(int j = 0; j < 3; j++)
    	{
            char k = inf.readChar();
            ensuref('A' <= k && 'G' >= k, "Invalid character k");
            if(j != 2)
                inf.readSpace();
            else
                inf.readEoln();
    	}
	}
    inf.readEof();
    ensuref(ss.size() == n, "string duplicated");
    return 0;
}
