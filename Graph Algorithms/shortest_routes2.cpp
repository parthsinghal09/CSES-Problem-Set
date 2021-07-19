#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int m;
    int q;
    cin>>n; 
    cin>>m;
    cin>>q;
    
    vector<vector<long long int> > v;
    for(int i = 0; i<n; i++){
        
        vector<long long int> v1;
        for(int j = 0; j<n; j++){
            
            if(i == j){
                
                v1.push_back((long long)0);
                
            } else {
                
                v1.push_back((long long)1000000000000000);
                
            }
            
        }
        v.push_back(v1);
        
    }
    
    for(int i = 0; i<m; i++){
        
        int x;
        int y;
        long long int d;
        cin>>x;
        cin>>y;
        cin>>d;
        v[x - 1][y - 1] = min(v[x - 1][y - 1], d);
        v[y - 1][x - 1] = min(v[y - 1][x - 1], d);
        
    }
    
    for(int i = 0; i<n; i++){
        
        for(int j = 0; j<n; j++){
            
            for(int k = 0; k<n; k++){
                
                v[j][k] = (long long)min(v[j][k], (long long)(v[j][i] + v[i][k]));
                    
            }
            
        }
        
    }
    
    for(int i = 0; i<q; i++){
        
        int a;
        int b;
        cin>>a;
        cin>>b;
        if(v[a - 1][b - 1] == (long long)1000000000000000){
            
            cout<<-1<<endl;
            
        } else {
            
            cout<<v[a - 1][b - 1]<<endl;
            
        }
        
    }
    
    
    return 0;
}