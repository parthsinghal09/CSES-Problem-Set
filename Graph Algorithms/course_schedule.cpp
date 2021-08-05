#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& course, vector<int>& vis, vector<int>& t, int node, int& tab){
    
    for(int i = 0; i<course[node].size(); i++){
        
        if(tab>0){
            
            break;
            
        }
        
        int temp = course[node][i];
        if(vis[temp] == -1){
            
            vis[temp] = 0;
            dfs(course, vis, t, temp, tab);
            
        } else if(vis[temp] == 0){
            
            tab++;
            
        }
        
    }
    
    vis[node] = 1;
    t.push_back(node);
    
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
    
    vector<int> list;
    int a = 0;
    for(int i = 0; i<n; i++){
        
        if(b[i] == -1){
            
            int count = 0;
            b[i] = 0;
            dfs(v, b, list, i, count);
            if(count>0){
                
                a = count;
                break;
                
            }
        
        }
        
    }
    
    if(a>0){
        
        cout<<"IMPOSSIBLE"<<endl;
        
    } else {
        
    
        for(int i = (list.size() - 1); i>=0; i--){
            
            cout<<list[i]+ 1<<" ";
            
        }
        cout<<endl;
        
    }

    return 0;
}
