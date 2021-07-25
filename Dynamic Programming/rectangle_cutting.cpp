#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a;
    int b;
    cin>>a;
    cin>>b;
    
    if(a>b){
        
        int temp = a;
        a = b;
        b = temp;
        
    }
    
    vector<vector<int> > dp;
    for(int i = 0; i<=a; i++){
        
        vector<int> v;
        for(int j = 0; j<=b; j++){
            
            if(i == 0){
                
                v.push_back(0);
                
            } else if(j == 0){
                
                v.push_back(0);
                
            } else {
                
                v.push_back(1e9);
                
            }
            
        }
        
        dp.push_back(v);
        
    }
    
    for(int i = 1; i<=a; i++){
        
        for(int j = 1; j<=b; j++){
            
            if(i!=j){
                
                for(int k = 1; k<i; k++){
                    
                    dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
                    
                }
                
                for(int k = 1; k<j; k++){
                    
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                    
                }
                
            } else {
                
                dp[i][j] = 0;
                
            }
            
        }
        
    }
    
    cout<<dp[a][b]<<endl;
    
    return 0;
}