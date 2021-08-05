#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int m;
    cin>>n; 
    cin>>m;
    
    vector<pair<pair<int, int>, long long int> > edge;
    for(int i = 0; i<m; i++){
        
        int a; 
        int b;
        long long int c;
        cin>>a;
        cin>>b;
        cin>>c;
        a = a - 1;
        b = b - 1;
        edge.push_back(make_pair(make_pair(a, b), c));
        
    }
    
    vector<long long int> d;
    vector<int> par;
    for(int i = 0; i<n; i++){
        
        d.push_back((long long)9e18);
        par.push_back(-1);
        
    }
    
    d[0] = (long long)0;
    
    int tab;
    
    for(int i = 0; i<n; i++){
        
        int t = -1;
        for(int j = 0; j<m; j++){
            
            pair<pair<int, int>, long long int> p = edge[j];
            pair<int, int> p1 = p.first;
            int x = p1.first;
            int y = p1.second;
            long long int w = p.second;
            
            if(d[y]>(d[x] + w)){
                
                d[y] = d[x] + w;
                par[y] = x;
                t = y;
                
            }
            
        }
        
        tab = t;
        
    }
    
    if(tab == -1){
        
        cout<<"NO"<<endl;
        
    } else {
        
        cout<<"YES"<<endl;
        for(int i = 0; i<n; i++){
            
            tab = par[tab];
            
        }
        
        int temp = tab;
        vector<int> cycle;
        cycle.push_back(tab);
        while(1 == 1){
            
            tab = par[tab];
            if(temp == tab){
                
                break;
                
            } 
            
            cycle.push_back(tab);
            
        }
        
        for(int i = (cycle.size() - 1); i>=0; i--){
            
            cout<<cycle[i] + 1<<" ";
            
        }
        cout<<cycle[cycle.size() - 1] + 1<<endl;
        
    }

    return 0;
}