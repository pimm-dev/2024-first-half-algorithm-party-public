#include "testlib.h"
 
#include <vector>
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
 
    int n = opt<int>(1);
    int t = opt<int>(2);
 
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;
    shuffle(v.begin(), v.end());

    vector<int> vt(n);
    for (int i = 1; i < n; i++)
        vt[i] = rnd.next(0, t-1);
 
    cout << n << endl;
    
    vector<int> tt(t,0);
    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 1; i < n; i++) {
        edges[i][0] = v[tt[vt[i]]]+1;
        edges[i][1] = v[i]+1;
        tt[vt[i]] = i;
    }
    shuffle(edges.begin()+1, edges.end());

    for (int i = 1; i < n; i++)
        cout << edges[i][0] << " " << edges[i][1] << endl;
 
    int a = rnd.next(1,n);
    int b = rnd.next(1,n);
    while (a == b)
        b = rnd.next(1,n);
    
    cout << a << " " << b << endl;
}
