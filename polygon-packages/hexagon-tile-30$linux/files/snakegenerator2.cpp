#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int maxN = stoi(argv[1]);
	int maxM = stoi(argv[2]);
	int maxK = stoi(argv[3]);
	
	int n = maxN;
	int m = maxM;
	set<pair<int,int>> s;
	
	for(int i = 0;i < m-1;i++)
	{
	    s.insert({1,i});
	}
	
	bool up = true;
	for(int i = m-2;i >= 1;i--)
	{
	    if(i%2 == 0)
	        continue;
	    if(up)
	    {
	        for(int j = 2;j < n - 3;j++)
	            s.insert({j,i});
	    }
	    else
	    {
	        for(int j = n-3;j > 2;j--)
	            s.insert({j,i});
	    }
	    up = !up;
	}
	
	for(int i = 1;i < m;i++)
	{
	    s.insert({n-2,i});
	}
	
	int k = s.size();
	
	cout << n << " " << m << " " << k << endl;
	
	for(auto it : s)
	{
       cout << it.first << " " << it.second << endl;
	}
	
    return 0;
}
