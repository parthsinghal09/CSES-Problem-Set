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
    
    long long int mod = (long long)(1e9 + 7);
    
    vector<long long int> v;
    for(int i = 0; i<n; i++){
        
        long long int x;
        cin>>x;
        v.push_back(x);
        
    }
    
    vector<vector<long long int> > dp;
    for(int i = 0; i<n; i++){
        
        vector<long long int> v1;
        for(int j = 0; j<=m; j++){
            
            v1.push_back((long long)0);
            
        }
        
        dp.push_back(v1);
        
    }
    
    for(int i = 1; i<=m; i++){
        
        if(v[0] == 0){
            
            dp[0][i] = (long long)1;
            
        } else {
            
            if(i == v[0]){
                
                dp[0][i] = (long long)1;
                
            } 
            
        }
        
    }
    
    long long int ans = (long long)0;
    
    for(int i = 1; i<n; i++){
        
        if(v[i] == (long long)0){
            
            for(int j = 1; j<=m; j++){
                
                if((j - 1)>=1 && (j - 1)<=m){
                        
                    dp[i][j] = dp[i][j] + dp[i - 1][j - 1]%mod;
                    
                }
                
                dp[i][j] = dp[i][j] + dp[i - 1][j]%mod;
                
                if((j + 1)>=1 && (j + 1)<=m){
                    
                    dp[i][j] = dp[i][j] + dp[i - 1][j + 1]%mod;
                    
                }
                
            }
            
        } else {
            
            if((v[i] - (long long)1)>=1 && (v[i] - (long long)1)<=m){
                        
                dp[i][v[i]] = dp[i][v[i]] + dp[i - 1][(v[i] - (long long)1)]%mod;
                
            }
            
            dp[i][v[i]] = dp[i][v[i]] + dp[i - 1][v[i]]%mod;
            
            if((v[i] + (long long)1)>=1 && (v[i] + (long long)1)<=m){
                
                dp[i][v[i]] = dp[i][v[i]] + dp[i - 1][(v[i] + (long long)1)]%mod;
                
            }
                    
        }
        
    }
    
    for(int i = 0; i<=m; i++){
        
        ans = ans + dp[n - 1][i]%mod;
        
    }
    
    cout<<ans%mod<<endl;

    return 0;
}