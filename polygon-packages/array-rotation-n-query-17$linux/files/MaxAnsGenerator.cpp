#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	
	int n = 200000;
	int q = 200000;
	
	vector<bool> allowQuery(4);
	allowQuery[0] = 0;
	allowQuery[1] = stoi(argv[1]);
	allowQuery[2] = stoi(argv[2]);
	allowQuery[3] = stoi(argv[3]);
	
	cout << n << " " << q << "\n";
	
	vector<int> arr(n);
	for(int i = 0; i<n; i++)
	{
	    arr[i] = 1e9;
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
	        int a = rnd.next(1,1000);
	        int b = rnd.next(n-1000,n);
	        if(a > b)
	            swap(a,b);
	        cout << t << " " << a << " " << b << "\n";
	    }
	    else
	    {
	        int k = n-1;
	        cout << t << " " << k << "\n";
	    }
	}
	
	if(!allowQuery[3])
	{
	    int a = 1;
        int b = n;
        if(a > b)
            swap(a,b);
        cout << 3 << " " << a << " " << b << "\n";
	}
	
    return 0;
}
