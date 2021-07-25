#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<vector<char> > v;
    vector<vector<long long int> > dp;
    for(int i = 0; i<n; i++){
        
        vector<char> v1;
        vector<long long int> dp1;
        for(int j = 0; j<n; j++){
            
            char c;
            cin>>c;
            v1.push_back(c);
            dp1.push_back((long long)0);
            
        }
        
        v.push_back(v1);
        dp.push_back(dp1);
        
    }
    
    if(v[0][0]!='*'){
    
        dp[0][0] = (long long)1;
        
    }
    
    long long int mod = (long long)(1e9 + 7);
    
    for(int i = 0; i<n; i++){
        
        for(int j = 0; j<n; j++){
            
            if(i == 0 && j == 0){
                
                continue;    
                    
            }
            
            if(i == 0){
                
                if(v[i][j]!='*'){
                    
                    if(v[i][j - 1]!='*'){
                        
                        dp[i][j] = dp[i][j - 1]%mod;
                        
                    }
                    
                }
                
            } else if(j == 0){
                
                if(v[i][j]!='*'){
                    
                    if(v[i - 1][j]!='*'){
                        
                        dp[i][j] = dp[i - 1][j]%mod;
                        
                    }
                    
                }
                
            } else {
                
                if(v[i][j]!='*'){
                    
                    if(v[i - 1][j]!='*'){
                        
                        dp[i][j] = dp[i][j] + dp[i - 1][j]%mod;
                        
                    }
                    
                    if(v[i][j - 1]!='*'){
                        
                        dp[i][j] = dp[i][j] + dp[i][j - 1]%mod;
                        
                    }
                    
                }
                
            }
            
        }
        
    }
    
    /*for(int i = 0; i<n; i++){
        
        for(int j = 0; j<n; j++){
            
            cout<<dp[i][j]%mod<<" ";
            
        }
        cout<<endl;
        
    }*/
    
    cout<<dp[n - 1][n - 1]%mod<<endl;

    return 0;
}