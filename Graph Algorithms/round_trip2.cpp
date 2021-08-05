#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& city, vector<int>& vis, vector<int>& t, int node, int& tab, int& front, int& back){
    
    for(int i = 0; i<city[node].size(); i++){
        
        if(tab>0){
            
            break;
            
        } 
        
        int temp = city[node][i];
        if(vis[temp] == -1){
            
            vis[temp] = 0;
            t[temp] = node;
            dfs(city, vis, t, temp, tab, front, back);
            
        } else {
            
            if(vis[temp] == 0){
                
                back = node;
                front = temp;
                tab++;
                
            }
            
        }
        
    }
    
    vis[node] = 1;
    
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
    for(int i = 0; i<n; i++){
        
        vector<int> v1;
        v.push_back(v1);
        b.push_back(-1);
        
    }
    
    for(int i = 0; i<m; i++){
        
        int a; 
        int b;
        cin>>a;
        cin>>b;
        
        v[a - 1].push_back(b - 1);
        
    }
    
    vector<int> cycle;
    vector<int> a;
    for(int i = 0; i<n; i++){
        
        a.push_back(-1);
        
    }
    int start = -1;
    int end = -1;
    
    for(int i = 0; i<n; i++){
        
        if(b[i] == -1){
            
            b[i] = 0;
            if(v[i].size()>0){
                
                int count = 0;
                int be = -1;
                int fe = -1;
                
                dfs(v, b, a, i, count, fe, be);
                if(count>0){
                    
                    if(fe!=(-1) && be!=(-1)){
                        
                        start = fe;
                        end = be; 
                        int x = end;
                        cycle.push_back(end);
                        while(x!=start){
                            
                            cycle.push_back(a[x]);
                            x = a[x];
                            
                        }
                        break;
                        
                    }
                    
                }
                
            } else {
                
                b[i] = 1;
                
            }
            
        }
        
    }
    
    if(cycle.size() == 0){
        
        cout<<"IMPOSSIBLE"<<endl;
        
    } else {
        
        cout<<cycle.size() + 1<<endl;
        for(int i = (cycle.size() - 1); i>=0; i--){
            
            cout<<cycle[i]+ 1<<" ";
            
        }
        cout<<cycle[(cycle.size() - 1)] + 1<<endl;
        
    }

    return 0;
}