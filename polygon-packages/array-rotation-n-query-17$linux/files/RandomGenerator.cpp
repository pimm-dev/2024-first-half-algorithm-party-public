#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int maxN = stoi(argv[1]);
	
	int n = rnd.next(2,maxN);
	int q = stoi(argv[2]);
	int maxAi = stoi(argv[3]);
	
	vector<bool> allowQuery(4);
	allowQuery[0] = 0;
	allowQuery[1] = stoi(argv[4]);
	allowQuery[2] = stoi(argv[5]);
	allowQuery[3] = stoi(argv[6]);
	
	cout << n << " " << q << "\n";
	
	vector<int> arr(n);
	for(int i = 0; i<n; i++)
	{
	    arr[i] = rnd.next(1,maxAi);
	    cout << arr[i] << " \n"[i == n-1];
	}
	if(!allowQuery[3])
	    q--;
	while(q--)
	{
	    int t = 0;
	    while(!allowQuery[t])
	        t = rnd.next(1,3);
	    if(t == 3)
	    {
	        int a = rnd.next(1,n);
	        int b = rnd.next(1,n);
	        if(a > b)
	            swap(a,b);
	        cout << t << " " << a << " " << b << "\n";
	    }
	    else
	    {
	        int k = rnd.next(1,n);
	        cout << t << " " << k << "\n";
	    }
	}
	
	if(!allowQuery[3])
	{
	    int a = rnd.next(1,n);
        int b = rnd.next(1,n);
        if(a > b)
            swap(a,b);
        cout << 3 << " " << a << " " << b << "\n";
	}
	
    return 0;
}
