#include "testlib.h"
#include <iostream>
#include <set>
using namespace std;

vector<pair<int,int>> v;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
 
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int q = atoi(argv[3]);
    int minvalue = atoi(argv[4]);
    cout << n << " " << m << " " << q << endl;
    //1
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i!=j) v.push_back({i,j});
        }
    }
    //2
    
    shuffle(v.begin(),v.end());
    //3
    
    for(int i = 0;i<m;i++){
        cout<<v[i].first<<" " <<v[i].second<<" " << (((v[i].first + v[i].second)%2 == 1) ? minvalue : minvalue+1) << endl;
    }
    //4
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j) continue;
            int e = 0;
            while(e==0||i==e||e==j){
                e = rnd.next(1,n);
            }
            
            cout<<i<<" " <<j << " " << e << endl; 
        }
    }
    for(int i = n*(n-1)+1;i<=200000;i++){
        int s = 0;
        int e = 0;
        int k = 0;
        while(s==e||s==k||e==k){
            s = rnd.next(1,n);
            e = rnd.next(1,n);
            k = rnd.next(1,n);
        }
        
        cout<<s<<" " <<k << " " << e << endl; 
    }
    
    return 0;
}
