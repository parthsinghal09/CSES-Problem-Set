#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<int>  v;
    for(int i = 0; i<n; i++){
        
        int x; 
        cin>>x;
        v.push_back(x);
        
    }
    
    vector<int> lis;
    
    for(int i = 0; i<n; i++){
        
        auto itr = lower_bound(lis.begin(), lis.end(), v[i]);
        if(itr == lis.end()){
            
            lis.push_back(v[i]);
            
        } else {
            
            *itr = v[i];
            
        }
        
    }
    
    cout<<lis.size()<<endl;

    return 0;
}