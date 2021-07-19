#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<long long int> v;
    for(int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        v.push_back(p);
        
    }
    
    multiset<long long int> m;
    for(int i = 0; i<n; i++){
        
        auto itr = m.upper_bound(v[i]);
        if(itr!=m.end()){
            
            m.erase(itr);
            m.insert(v[i]);
            
        } else {
            
            m.insert(v[i]);
            
        }
        
    }
    
    cout<<m.size()<<endl;

    return 0;
}