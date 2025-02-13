#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int maxN = stoi(argv[1]);
	int maxX = stoi(argv[2]);
	
	int n = rnd.next(2,maxN);
	int x = rnd.next(0,min(maxX,n-1));
	cout << n << endl;
	string s;
	vector<int> pos(n);
	for(int i = 0; i<n; i++)
	{
	    s+='.';
	    pos[i] = i;
	}
	shuffle(pos.begin(), pos.end());
	
	for(int i = 0; i<x; i++)
	{
	    s[pos[i]] = 'X';
	}
	s[pos[x]] = 'O';
    cout << s << endl;
    return 0;
}
