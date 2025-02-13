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
	
	int n = 343;
	int m = 343;
	
	cout << n << " " << m << endl;
	
	char arr[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	    
	    for(int j = 0;j < 7;j++)
	    {
	        for(int k = 0;k < 7;k++)
	        {
	            for(int l = 0;l < 7;l++)
	            {
	                string tmp;
            	    while(true)
            	    {
            	        tmp = randomString(20);
            	        if(dp.find(tmp)==dp.end())
            	           break;
            	    }
            	    dp.insert(tmp);
	                cout << tmp.size() << ' ' << tmp << ' ';
	                char a = arr[j];
	                char b = arr[k];
	                char c = arr[l];
	                cout << a << ' ' << b  << ' ' <<  c  << ' ' << 'A' << ' ' << 'A' << ' ' << 'A' << ' ' << 'A' << endl; 
	            }
	        }
	    }
	
    for(int j = 0;j < 7;j++)
	    {
	        for(int k = 0;k < 7;k++)
	        {
	            for(int l = 0;l < 7;l++)
	            {
	                char a = arr[j];
	                char b = arr[k];
	                char c = arr[l];
	                cout << a << ' ' << b  << ' ' <<  c  << endl; 
	            }
	        }
	    }
	
    return 0;
}
