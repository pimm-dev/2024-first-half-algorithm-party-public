#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int maxN = stoi(argv[1]);
	int maxM = stoi(argv[2]);
	int maxK = stoi(argv[3]);
	
	int n = rnd.next(2,maxN);
	int m = rnd.next(2,maxM);
	int k = rnd.next(0, n*m - 2);
	
	cout << n << " " << m << " " << k << endl;
	
   set<pair<int,int>> s;
	for(int i = 0; i < k; i++)
	{
      while(true)
      {
	      int y = rnd.next(0, n-1);
         int x = rnd.next(0, m-1);

         //출발지
         if(y == 0 && x == 0)
            continue;

         //탈출구
         if(y == n-1 && x == m-1)
            continue;
         
         //중복체크
         if(s.find({y,x}) != s.end())
            continue;


	     cout << y << " " << x << endl;
	     s.insert({y, x});
         break;
      }
	}
	
    return 0;
}
