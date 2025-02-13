#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int minN = stoi(argv[1]);
	int maxN = stoi(argv[2]);
	int type = stoi(argv[3]);
	
	int n = rnd.next(minN,maxN);
	cout << n << endl;
	
	
	string s(n,' ');
	
	vector<string> caseT = {"O", "XOX", "XO.", "X.O.X", "X.O..", "..O.."};
	
	int posO = rnd.next(0,n-1);
	
	vector<int> pos;
	s[posO] = 'O';
	int cnt = caseT[type].size()/2;
	
	if(rnd.next(0,1))
	    reverse(caseT[type].begin(),caseT[type].end());
	   
	for(int i = max(0,posO-cnt); i < posO; i++)
	    s[i] = caseT[type][i-(posO-cnt)];
	    
	for(int i = min(n-1,posO+cnt); i > posO; i--)
	    s[i] = caseT[type][cnt*2-(posO+cnt-i)];
	    
	    
	for(int i = 0; i<n; i++)
	{
	    if(s[i] == ' ')
	    {
	        s[i] = '.';
	        pos.push_back(i);
	    }
	}
	shuffle(pos.begin(), pos.end());
	cnt = pos.size();
	
	int x = rnd.next(0,cnt);
	for(int i = 0; i<x; i++)
	    s[pos[i]] = 'X';
    cout << s << endl;
    return 0;
}
