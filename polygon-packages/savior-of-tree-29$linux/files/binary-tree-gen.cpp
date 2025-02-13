#include "testlib.h"
 
#include <vector>
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
 
    int n = opt<int>(1);
    int pa = opt<int>(2);
    int pb = opt<int>(3);
    
    cout << n << endl;

    vector<int> v(n+1);
    for (int i = 0; i < n+1; i++)
        v[i] = i;
    shuffle(v.begin() + 1, v.end());

    vector<vector<int>> edges(n-1,vector<int>(2));
    for (int i = 2; i < n+1; i++){
        edges[i-2][0] = v[i/2];
        edges[i-2][1] = v[i];
    }
    shuffle(edges.begin(), edges.end());

    for (int i = 0; i < n-1; i++)
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
        a = v[pa];
        b = v[pb];
    }
    
    cout << a << " " << b << endl;
}
