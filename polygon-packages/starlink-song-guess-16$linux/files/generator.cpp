#include "testlib.h"
#include <bits/stdc++.h>
#include <string>
 
using namespace std;

set<string> dp;

string randomString(int L)
{
    string ret = "";
    int l = rnd.next(1,L);
    for(int i = 0;i < l;i++)
    {
        if(rnd.next(0,1))
            ret += 'a' + rnd.next(0,25);
        else
            ret += 'A' + rnd.next(0,25);
    }
    return ret;
}
 
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int maxN = stoi(argv[1]);
	int maxM = stoi(argv[2]);
	int maxL = stoi(argv[3]);
	
	int n = rnd.next(10,maxN);
	int m = rnd.next(10,maxM);
	
	cout << n << " " << m << endl;
	
	char arr[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	vector<vector<char>> s;
	for(int i = 0;i < n;i++)
	{
	    vector<char> ss;
	    string tmp;
	    while(true)
	    {
	        tmp = randomString(maxL);
	        if(dp.find(tmp)==dp.end())
	           break;
	    }
	    dp.insert(tmp);
	    cout << tmp.size() << ' ' << tmp << ' ';
	    for(int j = 0; j < 7; j++)
    	{
           char a = arr[rnd.next(0, 6)];
            cout << a;
            ss.push_back(a);
           if(j!=6)
             cout << ' ';
    	}
    	s.push_back(ss);
    	cout << endl;
	}
	vector<vector<char>> v;
	for(int i = 0;i < m/2;i++)
	{
	    vector<char> vv;
	    for(int j = 0; j < 3; j++)
    	{
           char a = arr[rnd.next(0, 6)];
           vv.push_back(a);
    	}
    	v.push_back(vv);
	}
	
	for(int i = m/2;i < m;i++)
	{
	    vector<char> vv;
	    vector<char> f = s[rnd.next(0,n-1)];
	    for(int j = 0; j < 3; j++)
    	{
           char a = f[j];
           vv.push_back(a);
    	}
    	v.push_back(vv);
	}
	
	for(int i = 0;i < m;i++)
	{
	    for(int j = 0; j < 3; j++)
    	{
           char a = v[i][j];
            cout << a;
           if(j!=2)
             cout << ' ';
    	}
    	cout << endl;
	}
	
    return 0;
}
