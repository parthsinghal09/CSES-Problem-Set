#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& cityv, vector<int>& vis, int city){
    
    for(int i = 0; i<cityv[city].size(); i++){
        
        if(vis[cityv[city][i]] == 0){
            
            vis[cityv[city][i]] = 1;
            dfs(cityv, vis, cityv[city][i]);
            
        }
        
    }
    
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; 
    int m;
    cin>>n;
    cin>>m;
    
    vector<vector<int> > v;
    
    for(int i = 0; i<n; i++){
        
        vector<int> pv;
        v.push_back(pv);
        
    }
    
    vector<int> b;
    for(int i = 0; i<n; i++){
        
        b.push_back(0);
        
    }
    
    for(int i = 0; i<m; i++){
        
        int x;
        int y; 
        cin>>x;
        cin>>y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);

    }
    
    vector<int> con;
    
    for(int i = 0; i<n; i++){
        
        if(b[i] == 0){
            
            b[i] = 1;
            dfs(v, b, i);
            con.push_back(i + 1);
            
        }
        
    }
    
    int count = con.size() - 1;
    
    cout<<count<<endl;
    
    for(int i = 1; i<con.size(); i++){
        
        cout<<con[i - 1]<<" "<<con[i]<<endl;
        
    }
    
    return 0;
}