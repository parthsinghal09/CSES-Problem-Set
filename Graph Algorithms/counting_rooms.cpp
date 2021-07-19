#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<vector<char> >& mm, vector<vector<int> >& vis){
    
    int x1 = x;
    int y1 = y + 1;
    int x2 = x;
    int y2 = y - 1;
    int x3 = x + 1;
    int y3 = y;
    int x4 = x - 1;
    int y4 = y;
    
    if(x1>=0 && y1>=0 && x1<mm.size() && y1<mm[0].size()){
        
        if(mm[x1][y1] == '.' && vis[x1][y1] == 0){
            
            vis[x1][y1] = 1;
            dfs(x1, y1, mm, vis);
            
        }
        
    }
    
    if(x2>=0 && y2>=0 && x2<mm.size() && y2<mm[0].size()){
        
        if(mm[x2][y2] == '.' && vis[x2][y2] == 0){
            
            vis[x2][y2] = 1;
            dfs(x2, y2, mm, vis);
            
        }
        
    }
    
    if(x3>=0 && y3>=0 && x3<mm.size() && y3<mm[0].size()){
        
        if(mm[x3][y3] == '.' && vis[x3][y3] == 0){
            
            vis[x3][y3] = 1;
            dfs(x3, y3, mm, vis);
            
        }
        
    }
    
    if(x4>=0 && y4>=0 && x4<mm.size() && y4<mm[0].size()){
        
        if(mm[x4][y4] == '.' && vis[x4][y4] == 0){
            
            vis[x4][y4] = 1;
            dfs(x4, y4, mm, vis);
            
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
    
    vector<vector<char> > v;
    vector<vector<int> > b;
    for(int i = 0; i<n; i++){
        
        vector<char> cv;
        vector<int> b1;
        for(int j = 0; j<m; j++){
            
            char a;
            cin>>a;
            cv.push_back(a);
            b1.push_back(0);
            
        }
        
        v.push_back(cv);
        b.push_back(b1);
        
    }
    
    int count = 0;
    
    for(int i = 0; i<n; i++){
        
        for(int j = 0; j<m; j++){
            
            if(v[i][j] == '.' && b[i][j] == 0){
                
                b[i][j] = 1;
                dfs(i, j, v, b);
                count++;
                
            }
            
        }
        
    }
    
    cout<<count<<endl;

    return 0;
}