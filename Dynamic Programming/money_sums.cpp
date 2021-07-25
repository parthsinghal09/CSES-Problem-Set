#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<int> v;
    int sum = 0;
    for(int i = 0; i<n; i++){
        
        int x;
        cin>>x;
        v.push_back(x);
        sum = sum + x;
        
    }
    
    vector<vector<int> > dp;
    for(int i = 0; i<=n; i++){
        
        vector<int> v1;
        for(int j = 0; j<=sum; j++){
            
            v1.push_back(0);
            
        }
        dp.push_back(v1);
        
    }
    
    dp[0][0] = 1;
    
    for(int i = 1; i<=n; i++){
        
        for(int j = 0; j<=sum; j++){
            
            dp[i][j] = dp[i - 1][j];
            if((j - v[i - 1]) == 0){
                
                dp[i][j] = 1;
                
            } else if((j - v[i - 1])>0){
                
                if(dp[i - 1][j - v[i - 1]] == 1){
                    
                    dp[i][j] = 1;
                    
                }
                
            }
            
        }
        
    }
    
    int count = 0;
    for(int i = 1; i<=sum; i++){
        
        if(dp[n][i] == 1){ 
            
            count++;
            
        }
        
    }
    
    cout<<count<<endl;
    
    for(int i = 1; i<=sum; i++){
        
        if(dp[n][i] == 1){ 
            
            cout<<i<<" ";
            
        }
        
    }
    cout<<endl;
    
    return 0;
}