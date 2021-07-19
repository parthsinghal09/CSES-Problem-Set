#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& city, vector<int>& vis, int node, int& tab, vector<int>& t, map<int, int>& cm, int& be, int& fe){
    
    for(int i = 0; i<city[node].size(); i++){
        
        if(tab>0){
            
            break;
            
        }
        
        int temp_n = city[node][i];
        if(vis[temp_n] == 0){
            
            vis[temp_n] = 1;
            t[temp_n] = node;
            cm[node] = temp_n;
            dfs(city, vis, temp_n, tab, t, cm, be, fe);
            
        } else {
            
            if(cm.find(temp_n)!=cm.end()){
                
                if(cm[temp_n]!=node){
                    
                    be = temp_n;
                    fe = node;
                    tab++;
                    
                }
                
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
    vector<set<int> > vs;
    vector<int> b;
    for(int i = 0; i<n; i++){
        
        vector<int> c;
        set<int> setc;
        vs.push_back(setc);
        v.push_back(c);
        b.push_back(0);
        
    }
    
    for(int j = 0; j<m; j++){
        
        int x;
        int y;
        cin>>x;
        cin>>y;
        v[x - 1].push_back(y - 1);
        v[y - 1].push_back(x - 1);
        vs[x - 1].insert(y - 1);
        vs[y - 1].insert(x - 1);
        
    }
    
    vector<int> ans;
    int start = -1;
    int end = -1;
    int c1 = 0;
    for(int i = 0; i<n; i++){
        
        if(b[i] == 0){
            
            c1 = c1 + 1;
            b[i] = 1;
            if(v[i].size()>0){
                int count = 0;
                vector<int> a;
                for(int i = 0; i<n; i++){
                    
                    a.push_back(-1);
                    
                }
                map<int, int> mc;
                int back_edge = -1;
                int front_edge = -1;
                dfs(v, b, i, count, a, mc, back_edge, front_edge);
                if(count!=0){
                    
                    ans = a;
                    start = back_edge;
                    end = front_edge;
                    break;
                    
                }
            
            }
            
        }
        
    }
    
    if(start == -1 && end == -1){
        
        
        cout<<"IMPOSSIBLE"<<endl;
        
    } else {
        
        int x = end;
        vector<int> ans1;
        ans1.push_back(end);
        while(x!=start){
            
            ans1.push_back(ans[x]);
            x = ans[x];
            
        }
        ans1.push_back(end);
        
        cout<<ans1.size()<<endl;
        for(int i = 0; i<ans1.size(); i++){
            
            cout<<ans1[i] + 1<<" ";
            
        }
        cout<<endl;
        
    }

    return 0;
}