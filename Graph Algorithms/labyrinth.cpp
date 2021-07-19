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
    
    vector<vector<char> > v;
    vector<vector<int> > b;
    
    int startx = 0;
    int starty = 0;
    int endx = 0;
    int endy = 0;
    
    for(int i = 0; i<n; i++){
        
        vector<char> pv;
        vector<int> bv;
        for(int j = 0; j<m; j++){
            
            char cc;
            cin>>cc;
            pv.push_back(cc);
            bv.push_back(0);
            
            if(cc == 'A'){
                
                startx = i;
                starty = j;
                
            }
            
            if(cc == 'B'){
                
                endx = i;
                endy = j;
                
            }
        
        }
        v.push_back(pv);
        b.push_back(bv);
        
    }
    
    queue<pair<int, int> > q;
    q.push(make_pair(startx, starty));
    
    vector<vector<pair<int, int> > > tab;
    for(int i = 0; i<n; i++){
        
        vector<pair<int, int> > tt;
        for(int j = 0; j<m; j++){
            
            if(i == startx && j == starty){
                
                tt.push_back(make_pair(-2, -2));
                
            } else {
                
                tt.push_back(make_pair(-1, -1));
                
            }
        }
        tab.push_back(tt);
        
    }
    
    while(!q.empty()){
        
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        b[x][y] = 1;
        if(x == endx && y == endy){
            
            break;
            
        }
        int x1 = x;
        int y1 = y + 1;
        int x2 = x;
        int y2 = y - 1;
        int x3 = x + 1;
        int y3 = y;
        int x4 = x - 1;
        int y4 = y;
        
        if(x1>=0 && y1>=0 && x1<n && y1<m){
        
            if((v[x1][y1] == '.' || v[x1][y1] == 'B') && b[x1][y1] == 0){
                
                b[x1][y1] = 1;
                q.push(make_pair(x1, y1));
                tab[x1][y1] = make_pair(x, y);
                
            }
            
        }
        
        if(x2>=0 && y2>=0 && x2<n && y2<m){
            
            if((v[x2][y2] == '.' || v[x2][y2] == 'B') && b[x2][y2] == 0){
                
                b[x2][y2] = 1;
                q.push(make_pair(x2, y2));
                tab[x2][y2] = make_pair(x, y);
                
            }
            
        }
        
        if(x3>=0 && y3>=0 && x3<n && y3<m){
            
            if((v[x3][y3] == '.' || v[x3][y3] == 'B') && b[x3][y3] == 0){
                
                b[x3][y3] = 1;
                q.push(make_pair(x3, y3));
                tab[x3][y3] = make_pair(x, y);
                
            }
            
        }
        
        if(x4>=0 && y4>=0 && x4<n && y4<m){
            
            if((v[x4][y4] == '.' || v[x4][y4] == 'B') && b[x4][y4] == 0){
                
                b[x4][y4] = 1;
                q.push(make_pair(x4, y4));
                tab[x4][y4] = make_pair(x, y);
                
            }
            
        }
        
    }
    
    /*for(int i = 0; i<n; i++){
        
        for(int j = 0; j<m; j++){
            
            
            cout<<"("<<tab[i][j].first<<","<<tab[i][j].second<<")"<<" ";
            
        }
        cout<<endl;
        
    }*/
    
    if(b[endx][endy] == 0){
        
        cout<<"NO"<<endl;
        
    } else {
        
        cout<<"YES"<<endl;
        
        vector<char> ans;
        
        pair<int, int> temp = tab[endx][endy];
        if(endx == temp.first){
            
            if(endy>temp.second){
                
                ans.push_back('R');
                
            } else {
                
                ans.push_back('L');
                
            }
            
        } else if(endy == temp.second){
            
            if(endx>temp.first){
                
                ans.push_back('D');
                
            } else {
                
                ans.push_back('U');
                
            }
            
        }
        
        while(temp.first!=-2 && temp.second!=-2){
            
            pair<int, int> temp1 = tab[temp.first][temp.second];
            
            if(temp.first == temp1.first){
            
                if(temp.second>temp1.second){
                    
                    ans.push_back('R');
                    
                } else {
                    
                    ans.push_back('L');
                    
                }
                
            } else if(temp.second == temp1.second){
                
                if(temp.first>temp1.first){
                    
                    ans.push_back('D');
                    
                } else {
                    
                    ans.push_back('U');
                    
                }
                
            }
            temp = temp1;
            
        }
        
        cout<<ans.size()<<endl;
        for(int i = (ans.size() - 1); i>=0; i--){
            
            cout<<ans[i];
            
        }
        cout<<endl;
        
    }
    

    return 0;
}