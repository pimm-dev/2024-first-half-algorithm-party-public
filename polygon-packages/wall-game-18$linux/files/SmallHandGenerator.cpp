/*
total 13case (추가 예정)
2
.O
5
..O..
5
.O...
5
X..O.
5
.X.O.
6
..O..X
7
.XX.O..
7
..O.X..
7
X..O..X
7
..O..X.
7
O......
7
..OX.XX
7
X.O..XX
*/
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]){
	registerGen(argc, argv, 1);
	
	int index = stoi(argv[1]);
	
	vector<string> table = {".O", "..O..", ".O...", "X..O.", ".X.O.", "..O..X", ".XX.O..", "..O.X..", "X..O..X", "..O..X.", "O......", "..OX.XX", "X.O..XX"};
	
	cout << table[index].size() << endl;
	cout << table[index] << endl;
    return 0;
}
