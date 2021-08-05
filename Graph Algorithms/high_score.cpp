#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int m;
    cin>>m;
    
    vector<pair<pair<int, int>, long long int > > v;
    for(int i = 0; i<m; i++){
        
        int a;
        int b;
        long long int c;
        cin>>a;
        cin>>b;
        cin>>c;
        a = a - 1;
        b = b - 1;
        c = (long long)((-1)*c);
        v.push_back(make_pair(make_pair(a, b), c));
        
    }
    
    vector<long long int> d;
    long long int neg_inf = ((long long)(-1)*(9e18));
    for(int i = 0; i<n; i++){
        
        d.push_back((long long)9e18);
        
    }
    
    d[0] = (long long)0;
    
    for(int i = 0; i<(n - 1); i++){

        for(int j = 0; j<m; j++){
            
            pair<pair<int, int>, long long int> p = v[j];
            int x = p.first.first;
            int y = p.first.second;
            long long int w = p.second;
            
            if(d[x] == (long long)(9e18)){
                
                continue;
                
            }
            
            d[y] = min(d[y], d[x] + w);
            d[y] = max(d[y], neg_inf);
            
        }
        
    }
    
    for(int i = 0; i<(n - 1); i++){
        
        for(int j = 0; j<m; j++){
            
            pair<pair<int, int>, long long int> p = v[j];
            int x = p.first.first;
            int y = p.first.second;
            long long int w = p.second;
            
            if(d[x] == (long long)(9e18)){
                
                continue;
                
            }
            
            if((d[x] + w)<d[y]){
                
                d[y] = neg_inf;
                
            }
            
        }
        
    }
    
    if(d[n - 1] == neg_inf){
        
        cout<<-1<<endl;
        
    } else {
        
        cout<<((long long)(-1)*d[n - 1])<<endl;
        
    }
    
    return 0;
}
