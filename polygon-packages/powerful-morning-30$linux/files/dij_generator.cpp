#include "testlib.h"
#include <iostream>
#include <set>
using namespace std;
 
vector<pair<int,int>> v;
 
int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
 
    int n = atoi(argv[1]);
    int order = atoi(argv[2]);
    cout << n << " " << n*(n-1) << " " << 200000 << endl;
    //1
    
    if(order == 1){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<n;j++){
                cout<< (i + j - 1)%n + 1 << " " << i << " " << 1 + (j-1)*(n-2) <<endl;
            }
        }
    }else if(order == 2){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<n;j++){
                cout<< (i + j - 1)%n + 1 << " " << i << " " << 1 + (n - j - 1)*(n-2) <<endl;
            }
        }
    }else if(order == 3){
        vector<int> v;
        for(int i = 1;i<n;i++){
            v.push_back(1 + (i-1)*(n-2));
        }
        for(int i = 1;i<=n;i++){
            shuffle(v.begin(),v.end());
            for(int j = 1;j<n;j++){
                cout<< (i + j - 1)%n + 1 << " " << i << " " << v[j-1] <<endl;
            }
        }
    }else {
        vector<int> v;
        for(int i = 1;i<=n;i++){
            v.push_back(i);
        }
        shuffle(v.begin(),v.end());
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<n;j++){
                cout<< v[(i + j - 1)%n] << " " << v[i-1] << " " << 1 + (n - j - 1)*(n-2) <<endl;
            }
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
