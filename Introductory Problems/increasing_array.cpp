#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    vector<long long int> v;
    for(long long int i = 0; i<n; i++){
        
        long long int k;
        cin>>k;
        v.push_back(k);
        
    }
    
    long long int ans = (long long)0;
    
    for(long long int i = 1; i<n; i++){
        
        if(v[i - 1]>v[i]){
            
            ans = (long long)(ans + (v[i - 1] - v[i]));
            v[i] = v[i - 1];
        }
        
    }
    
    cout<<ans<<endl;
    
    return 0;
    
}