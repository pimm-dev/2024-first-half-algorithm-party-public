#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int maxN = stoi(argv[1]);
	
	int n = rnd.next(maxN,maxN);
	int q = stoi(argv[2]);
	int maxAi = 63;
	int xbit = min(5,stoi(argv[3]));
	
	vector<bool> allowQuery(3);
	allowQuery[0] = 0;
	allowQuery[1] = stoi(argv[4]);
	allowQuery[2] = stoi(argv[5]);
	
	
	
	cout << n << " " << q << "\n";
	
	vector<int> arr(n);
	for(int i = 0; i<n; i++)
	{
	    arr[i] = rnd.next(0,maxAi);
	    arr[i]|=1<<xbit;
	    arr[i]^=1<<xbit;
	    cout << arr[i] << " \n"[i == n-1];
	}
	
    if(!allowQuery[1])
    {
        q--;
    }
	while(q--)
	{
	    int t = 0;
	    while(!allowQuery[t])
	        t = rnd.next(1,2);
	    int a = rnd.next(1,n);
	    int b = rnd.next(1,n);
	    while(t == 1 && abs(b-a) < 2)
	    {
	        a = rnd.next(1,n);
    	    b = rnd.next(1,n);
	    }
	    int c = rnd.next(0,maxAi);
	    c|=1<<xbit;
	    if(a > b)
	        swap(a,b);
	    cout << t << " " << a << " " << b << " " << c << "\n";
	}
	if(!allowQuery[1])
    {
        int a = rnd.next(1,n);
	    int b = rnd.next(1,n);
	    while(abs(b-a) < 2)
	    {
	        a = rnd.next(1,n);
    	    b = rnd.next(1,n);
	    }
	    int c = rnd.next(0,maxAi);
	    c|=1<<xbit;
	    if(a > b)
	        swap(a,b);
	    cout << 1 << " " << a << " " << b << " " << c << "\n";
    }
	
    return 0;
}
