#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int n;
    cin>>n;
    
    vector<long long int> v;
    for(long long int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        v.push_back(p);
        
    }
    
    map<long long int, long long int> m;
    
    long long int sum = (long long)0;
    long long int count = (long long)0;
    
    for(long long int i = 0; i<n; i++){
        
        long long int r = (sum%n + v[i]%n)%n;
        if(r<0){
            
            r = r + n;
            
        }
        sum = sum + v[i];
        
        if(r == 0){
            
            count++;
            
        } 
        
        if (m.find(r)!=m.end()){
            
            count = count + m[r];
            
        }
        
        m[r]++;
        
    }
    
    cout<<count<<endl;

    return 0;
}