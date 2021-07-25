#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n; 
    
    long long int mod = (long long)(1e9 + 7);
    
    long long int s = (n*(n + (long long)1))/((long long)2);
    
    if(s%2!=0){
        
        cout<<0<<endl;
        
    } else {
        
        long long int hs = s/((long long)2);
        vector<vector<long long int> > dp;
        for(int i = 0; i<=n; i++){
            
            vector<long long int> v1;
            for(int j = 0; j<=hs; j++){
                
                if(j!=0){
                    
                    v1.push_back((long long)0);
                    
                } else {
                    
                    v1.push_back((long long)1);
                    
                }
                
            }
            
            dp.push_back(v1);
            
        }
        
        for(int i = 1; i<=n; i++){
            
            for(int j = 1; j<=hs; j++){
                
                if((j - i)>=0){
                    
                    dp[i][j] = dp[i - 1][j]%mod + dp[i - 1][j - i]%mod;
                    
                } else {
                    
                    dp[i][j] = dp[i - 1][j]%mod;
                    
                }
                
            }
            
        }
        
        cout<<((dp[n][hs]/2)%mod)<<endl;
        
    }

    return 0;
}