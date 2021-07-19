#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n; 
    cin>>n;
    
    set<long long int> s; 
    
    for(int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        s.insert(p);
        
    }
    
    cout<<s.size()<<endl;
    
    return 0;
}