#include "testlib.h"
#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
 
    cout << 100 << " " << 9801 << " " << 200000 << endl;
    //1
    int n = 100;
    for(int i = 1;i<n;i++){
        cout<<  100 << " " <<i << " " << 1<<endl;
        for(int j = n-2;j>=1;j--){
            cout<< (i + j - 1)%(n-1) + 1 << " " << i << " " <<  2 + (j-1)*(n-3) <<endl;
        }
    }
    
    for(int i = 1;i<=100;i++){
        for(int j = 1;j<=100;j++){
            if(i==j) continue;
            int e = 0;
            while(e==0||i==e||e==j){
                e = rnd.next(1,n);
            }
            
            cout<<i<<" " <<j << " " << e << endl; 
        }
    }
    for(int i = 9901;i<=200000;i++){
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
