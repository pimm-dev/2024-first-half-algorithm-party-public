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
	
	bool up = true;
	for(int i = 1;i < n;i++)
	{
	    if(i%2 == 0)
	        continue;
	    if(up)
	    {
	        for(int j = 0;j < m - 1;j++)
	            s.insert({i,j});
	        
	    }
	    else
	    {
	        for(int j = m-1;j > 0;j--)
	            s.insert({i,j});
	    }
	    up = !up;
	}
	
	int k = s.size();
	
	cout << n << " " << m << " " << k << endl;
	
	for(auto it : s)
	{
       cout << it.first << " " << it.second << endl;
	}
	
    return 0;
}
