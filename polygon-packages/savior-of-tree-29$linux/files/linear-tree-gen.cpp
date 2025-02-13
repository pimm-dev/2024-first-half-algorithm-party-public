#include "testlib.h"
 
#include <vector>
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
 
    int n = opt<int>(1);
    int pa = opt<int>(2);
    int pb = opt<int>(3);
 
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = i;
    shuffle(v.begin(), v.end());
 
    vector<vector<int>> edges(n-1, vector<int>(2));
    for (int i = 0; i < n - 1; i++){
        edges[i][0] = v[i]+1;
        edges[i][1] = v[i+1]+1;
    }
    shuffle(edges.begin(), edges.end());
 
    cout << n << endl;
    
    for (int i = 0; i < n - 1; i++)
        cout << edges[i][0] << " " << edges[i][1] << endl;

    int a, b;
    
    if (pa == -1) {
        a = rnd.next(1, n);
        b = rnd.next(1, n);
        while (a == b)
            b = rnd.next(1, n);
    }
    else
    {
        a = v[pa] + 1;
        b = v[pb] + 1;
    }
    
    cout << a << " " << b << endl;
}
