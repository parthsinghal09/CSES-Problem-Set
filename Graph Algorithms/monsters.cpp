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
    
    vector<vector<char> > v;
    vector<vector<int> > timeM;
    vector<vector<int> > bM;
    vector<vector<int> > bA;
    queue<pair<pair<int, int>, int> > mon;
    for(int i = 0; i<n; i++){
        
        vector<char> v1;
        vector<int> tempM;
        vector<int> tempM1;
        for(int j = 0; j<m; j++){
            
            char c;
            cin>>c;
            v1.push_back(c);
            if(c == '#'){
                
                tempM.push_back(-1);
                
            } else {
                
                tempM.push_back(0);
                
            }
            
            if(c == 'M'){
                
                mon.push(make_pair(make_pair(i, j), 1));
                tempM1.push_back(1);
                
            } else {
                
                if(c == '#'){
                    
                    tempM1.push_back(1);
                    
                } else {
                    
                    tempM1.push_back(0);
                    
                }
                
            }
            
        }
        v.push_back(v1);
        timeM.push_back(tempM);
        bM.push_back(tempM1);
        bA.push_back(tempM);
        
    }
    
    while(!mon.empty()){
        
        pair<pair<int, int>, int> pm = mon.front();
        pair<int, int> pm1 = pm.first;
        int t = pm.second;
        mon.pop();
        int xm = pm1.first;
        int ym = pm1.second;
        
        int x1 = xm;
        int y1 = ym + 1;
        int x2 = xm + 1;
        int y2 = ym;
        int x3 = xm;
        int y3 = ym - 1;
        int x4 = xm - 1; 
        int y4 = ym;
        
        if(y1<m){
            
            if(bM[x1][y1] == 0 && (v[x1][y1]!='#')){
                
                bM[x1][y1] = 1;
                timeM[x1][y1] = t;
                mon.push(make_pair(make_pair(x1, y1), (t + 1)));
                
            } 
            
        }
        
        if(x2<n){
            
            if(bM[x2][y2] == 0 && (v[x2][y2]!='#')){
                
                bM[x2][y2] = 1;
                timeM[x2][y2] = t;
                mon.push(make_pair(make_pair(x2, y2), (t + 1)));
                
            } 
            
        }
        
        if(y3>=0){
            
            if(bM[x3][y3] == 0 && (v[x3][y3]!='#')){
                
                bM[x3][y3] = 1;
                timeM[x3][y3] = t;
                mon.push(make_pair(make_pair(x3, y3), (t + 1)));
                
            } 
            
        }
        
        if(x4>=0){
            
            if(bM[x4][y4] == 0 && (v[x4][y4]!='#')){
                
                bM[x4][y4] = 1;
                timeM[x4][y4] = t;
                mon.push(make_pair(make_pair(x4, y4), (t + 1)));
                
            } 
            
        }
        
    }
    
    /*for(int i = 0; i<n; i++){
        
        for(int j = 0; j<m; j++){
            
            cout<<timeM[i][j]<<" | ";
            
        }
        cout<<endl;
        
    }
    cout<<endl;*/
    
    vector<vector<pair<int, int> > > mazeA;
    vector<pair<int, int> > pA;
    int xA;
    int yA;
    for(int i = 0; i<n; i++){
        
        vector<pair<int, int> > v2;
        for(int j = 0; j<m; j++){
            
            if(v[i][j] == 'A'){
                
                xA = i;
                yA = j;
                v2.push_back(make_pair(-2, -2));
                
            } else {
                
                v2.push_back(make_pair(-1, -1));
                if(i == 0 || i == (n - 1)){
                    
                    if(v[i][j] == '.'){
                        
                        pA.push_back(make_pair(i, j));
                        
                    }
                    
                } else if(j == 0 || j == (m - 1)){
                    
                    if(v[i][j] == '.'){
                        
                        pA.push_back(make_pair(i, j));
                        
                    }
                    
                }
                
            }
            
        }
        mazeA.push_back(v2);
        
    }
    
    /*for(int i = 0; i<n; i++){
            
        for(int j = 0; j<m; j++){
            
            cout<<mazeA[i][j].first<<" "<<mazeA[i][j].second<<" | ";
            
        }
        cout<<endl;
        
    }*/
    
    if(xA == 0 || xA == (n - 1)){
        
        cout<<"YES"<<endl;
        cout<<0<<endl;
        
    } else if (yA == 0 || yA == (m - 1)){
        
        cout<<"YES"<<endl;
        cout<<0<<endl;
        
    } else {
        
        queue<pair<pair<int, int>, int> > qA;
        qA.push(make_pair(make_pair(xA, yA), 0));
        
        while(!qA.empty()){
            
            pair<pair<int, int>, int> pa = qA.front();
            pair<int, int> node = pa.first;
            int timeA = pa.second;
            qA.pop();
            
            int x = node.first;
            int y = node.second;
            
            bA[x][y] = 1;
            
            int x1 = x;
            int y1 = y + 1;
            int x2 = x + 1;
            int y2 = y;
            int x3 = x;
            int y3 = y - 1;
            int x4 = x - 1;
            int y4 = y;
            
            if(y1<m){
                
                if(bA[x1][y1] == 0 && (v[x1][y1]!='#') && (timeM[x1][y1]>(timeA + 1) || timeM[x1][y1] == 0)){
                    
                    bA[x1][y1] = 1;
                    qA.push(make_pair(make_pair(x1, y1), (timeA + 1)));
                    mazeA[x1][y1] = make_pair(x, y);
                    
                }
                
            }
            
            if(x2<n){
                
                if(bA[x2][y2] == 0 && (v[x2][y2]!='#') && (timeM[x2][y2]>(timeA + 1) || timeM[x2][y2] == 0)){
                    
                    bA[x2][y2] = 1;
                    qA.push(make_pair(make_pair(x2, y2), (timeA + 1)));
                    mazeA[x2][y2] = make_pair(x, y);
                    
                }
                
            }
            
            if(y3>=0){
                
                if(bA[x3][y3] == 0 && (v[x3][y3]!='#') && (timeM[x3][y3]>(timeA + 1) || timeM[x3][y3] == 0)){
                    
                    bA[x3][y3] = 1;
                    qA.push(make_pair(make_pair(x3, y3), (timeA + 1)));
                    mazeA[x3][y3] = make_pair(x, y);
                    
                }
                
            }
            
            if(x4>=0){
                
                if(bA[x4][y4] == 0 && (v[x4][y4]!='#') && (timeM[x4][y4]>(timeA + 1) || timeM[x4][y4] == 0)){
                    
                    bA[x4][y4] = 1;
                    qA.push(make_pair(make_pair(x4, y4), (timeA + 1)));
                    mazeA[x4][y4] = make_pair(x, y);
                    
                }
                
            }
            
        }
        
        /*for(int i = 0; i<n; i++){
            
            for(int j = 0; j<m; j++){
                
                cout<<mazeA[i][j].first<<" "<<mazeA[i][j].second<<" | ";
                
            }
            cout<<endl;
            
        }*/
        
        int d = 0;
        int j = 0;
        for(int i = 0; i<pA.size(); i++){
            
            pair<int, int> pA_temp = mazeA[pA[i].first][pA[i].second];
            int x_temp = pA_temp.first;
            int y_temp = pA_temp.second;
            if(x_temp == (-1) && y_temp == (-1)){
                
                continue;
                
            } else {
                
                j = i;
                while(x_temp!=(-2) && y_temp!=(-2)){
                                
                    d = d + 1;
                    int x_temp1 = mazeA[x_temp][y_temp].first;
                    int y_temp1 = mazeA[x_temp][y_temp].second;
                    x_temp = x_temp1;
                    y_temp = y_temp1;
                                
                }
                
                break;
                
            }
            
        }
        
        if(d == 0){
            
            cout<<"NO"<<endl;
            
        } else {
            
            cout<<"YES"<<endl;
            cout<<d<<endl;
            int ans_x = pA[j].first;
            int ans_y = pA[j].second;
            pair<int, int> temp_p = mazeA[ans_x][ans_y];
            int x_temp = temp_p.first;
            int y_temp = temp_p.second;
            
            vector<char> ans;
            
            while(x_temp!=(-2) && y_temp!=(-2)){
                
                if(x_temp == ans_x){
                    
                    if(y_temp<ans_y){
                        
                        ans.push_back('R');
                        
                    } else if(y_temp>ans_y){
                        
                        ans.push_back('L');
                        
                    }
                    
                    ans_x = x_temp;
                    ans_y = y_temp;
                    x_temp = mazeA[ans_x][ans_y].first;
                    y_temp = mazeA[ans_x][ans_y].second;
                    
                } else if(y_temp == ans_y){
                    
                    if(x_temp<ans_x){
                        
                        ans.push_back('D');
                        
                    } else if(x_temp>ans_x){
                        
                        ans.push_back('U');
                        
                    }
                    
                    ans_x = x_temp;
                    ans_y = y_temp;
                    x_temp = mazeA[ans_x][ans_y].first;
                    y_temp = mazeA[ans_x][ans_y].second;
                    
                }
                
            }
            
            for(int i = (ans.size() - 1); i>=0; i--){
                
                cout<<ans[i]<<"";
                
            }
            cout<<endl;
            
        }
        
    }
    
    
    return 0;
}