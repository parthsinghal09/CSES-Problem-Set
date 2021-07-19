#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& f, vector<int>& vis, vector<int>& colors, int node, int& tab){
    
    for(int i = 0; i<f[node].size(); i++){
        
        if(vis[f[node][i]] == 0){
            
            vis[f[node][i]] = 1;
            if(colors[node] == 1){
                
                colors[f[node][i]] = 2;
                
            } else if(colors[node] == 2){
                
                colors[f[node][i]] = 1;
                
            }
            
            dfs(f, vis, colors, f[node][i], tab);
            
        } else {
            
            if(colors[node] == colors[f[node][i]]){
                
                tab++;
                
            }
            
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
    vector<int> b;
    vector<int> teams;
    for(int i = 0; i<n; i++){
        
        vector<int> ex;
        v.push_back(ex);
        b.push_back(0);
        teams.push_back(0);
        
    }
    
    for(int i = 0; i<m; i++){
        
        int x;
        int y;
        cin>>x;
        cin>>y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
        
    }
    
    int count = 0;
    
    for(int i = 0; i<n; i++){
        
        if(b[i] == 0){
            
            b[i] = 1;
            teams[i] = 1;
            dfs(v, b, teams, i, count);
            
        }
        
    }
    
    if(count == 0){
        
        for(int i = 0; i<teams.size(); i++){
            
            cout<<teams[i]<<" ";
            
        }
        cout<<endl;
        
    } else {
        
        cout<<"IMPOSSIBLE"<<endl;
        
    }

    return 0;
}