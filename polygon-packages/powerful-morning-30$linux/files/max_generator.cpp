#include "testlib.h"
#include <iostream>
#include <set>
using namespace std;

vector<pair<int,int>> v;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    cout << 100 << " " << 198 << " " << 200000 << endl;
    //1
    
    for(int i = 1;i<=99;i++){
        cout<<i<<" " <<i+1<<" " << 10000 << endl;
        cout<<101-i<<" " <<100-i<<" " << 10000 << endl;
    }
    //4
    
    cout<<1<<" "<<100<<" "<<99<<endl;
    cout<<100<<" "<<1<<" "<<2<<endl;
    for(int i = 3;i<=200000;i++){
        int s = 0;
        int e = 0;
        int k = 0;
        while(s==e||s==k||e==k){
            s = rnd.next(1,100);
            e = rnd.next(1,100);
            k = rnd.next(1,100);
        }
        
        cout<<s<<" " <<k << " " << e << endl; 
    }
    
    return 0;
}
