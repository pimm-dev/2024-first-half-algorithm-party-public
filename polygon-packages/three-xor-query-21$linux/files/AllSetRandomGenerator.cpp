#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int minN = stoi(argv[1]);
	int maxN = stoi(argv[2]);
	int n = rnd.next(minN,maxN);
	
	int q = stoi(argv[3]);
	int minAi = stoi(argv[4]);
	int maxAi = stoi(argv[5]);
	
	vector<bool> allowQuery(3);
	allowQuery[0] = 0;
	allowQuery[1] = stoi(argv[6]);
	allowQuery[2] = stoi(argv[7]);
	
	int query1LeftMin = min(n,stoi(argv[8]));
	int query1LeftMax = min(n,stoi(argv[9]));
	int query1RightMin = min(n,stoi(argv[10]));
	int query1RightMax = min(n,stoi(argv[11]));
	int query1MinX = stoi(argv[12]);
	int query1MaxX = stoi(argv[13]);
	
	int query2LeftMin = min(n,stoi(argv[14]));
	int query2LeftMax = min(n,stoi(argv[15]));
	int query2RightMin = min(n,stoi(argv[16]));
	int query2RightMax = min(n,stoi(argv[17]));
	int query2MinX = stoi(argv[18]);
	int query2MaxX = stoi(argv[19]);
	cout << n << " " << q << "\n";
	
	vector<int> arr(n);
	for(int i = 0; i<n; i++)
	{
	    arr[i] = rnd.next(minAi,maxAi);
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
	        int a = 0;
    	    int b = 0;
    	    while(abs(b-a) < 2)
    	    {
    	        a = rnd.next(query1LeftMin,query1LeftMax);
        	    b = rnd.next(query1RightMin,query1RightMax);
    	    }
    	    int c = rnd.next(query1MinX,query1MaxX);
    	    if(a > b)
    	        swap(a,b);
    	    cout << 1 << " " << a << " " << b << " " << c << "\n";
	    }
	    else
	    {
	        int a = rnd.next(query2LeftMin,query2LeftMax);
        	int b = rnd.next(query2RightMin,query2RightMax);
    	    int c = rnd.next(query2MinX,query2MaxX);
    	    if(a > b)
    	        swap(a,b);
    	    cout << 2 << " " << a << " " << b << " " << c << "\n";
	    }
	}
    return 0;
}
