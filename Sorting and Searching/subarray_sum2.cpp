#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long int x;
    cin>>n; 
    cin>>x;
    
    vector<long long int> v;
    for(int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        v.push_back(p);
    
    }
    
    
    vector<long long int> prefix;
    long long int sum = (long long)0;
    for(int i = 0; i<n; i++){
        
        sum = sum +v[i];
        prefix.push_back(sum);
        
    }
    
    long long int count = (long long)0;
    map<long long int, int> m;
    
    for(int i = 0; i<prefix.size(); i++){
        
        if(prefix[i] == x){
            
            count++;
            
        } 
        
        if(m.find(prefix[i] - x)!=m.end()){
            
            count = count + m[prefix[i] - x];
            
        }
        
        m[prefix[i]]++;
        
    }
    
    cout<<count<<endl;

    return 0;
}