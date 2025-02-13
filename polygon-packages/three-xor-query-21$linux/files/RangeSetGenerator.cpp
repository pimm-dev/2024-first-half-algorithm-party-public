#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int minN = stoi(argv[1]);
	int maxN = stoi(argv[2]);
	int n = rnd.next(minN,maxN);
	int q = stoi(argv[3]);
	int maxAi = stoi(argv[4]);
	
	vector<bool> allowQuery(3);
	allowQuery[0] = 0;
	allowQuery[1] = stoi(argv[5]);
	allowQuery[2] = stoi(argv[6]);
	
	int mindiff = max(3,min(n,stoi(argv[7])));
	int maxdiff = max(3, min(n,stoi(argv[8])));
	cout << n << " " << q << "\n";
	
	vector<int> arr(n);
	for(int i = 0; i<n; i++)
	{
	    arr[i] = rnd.next(0,maxAi);
	    cout << arr[i] << " \n"[i == n-1];
	}
	
	bool isOne = false;
	while(q--)
	{
	    int t = 0;
	    while(!allowQuery[t])
	        t = rnd.next(1,2);
	    if(t == 1)
	        isOne = true;
	        
	    //1번 쿼리가 없을 때 마지막 쿼리를 1번 쿼리로 
	    if(q == 0 && !isOne || t == 1)
	    {
    	    int diff = rnd.next(mindiff,maxdiff);
    	    int a = rnd.next(1,n-diff+1);
    	    int b = a+diff-1;
    	    
    	    int c = rnd.next(0,maxAi);
    	    if(a > b)
    	        swap(a,b);
    	    cout << 1 << " " << a << " " << b << " " << c << "\n";
	    }
	    else
	    {
	        int diff = rnd.next(mindiff,maxdiff);
    	    int a = rnd.next(1,n-diff+1);
    	    int b = a+diff-1;
    	    
    	    int c = rnd.next(0,maxAi);
    	    if(a > b)
    	        swap(a,b);
    	    cout << 2 << " " << a << " " << b << " " << c << "\n";
	    }
	}
    return 0;
}
