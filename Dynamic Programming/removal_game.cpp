#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<long long int> v;
    for(int i = 0; i<n; i++){
            
        long long int x;
        cin>>x;
        v.push_back(x);
        
    }
        
    vector<vector<long long int> > dp;
    for(int i = 0; i<n; i++){
        
        vector<long long int> v1;
        for(int j = 0; j<n; j++){
            
            if(i == j){
                
                v1.push_back(v[i]);
                
            } else if((j - i) == 1){
                
                v1.push_back(max(v[i], v[j]));
                
            } else {
                
                v1.push_back((long long)0);
                
            }
            
        }
        
        dp.push_back(v1);
        
    }
    
    for(int l = 1; l<=n; l++){
        
        for(int i = 0; (i + l)<=n; i++){
            
            int j = i + l - 1;
            
            if(j>=2){
                
                if((j - i)>1){
                    
                    dp[i][j] = max((min(dp[i + 2][j], dp[i + 1][j - 1]) + v[i]), (min(dp[i + 1][j - 1], dp[i][j - 2]) + v[j]));
                
                }    
                
            }
            
        }
        
    }
    cout<<dp[0][n - 1]<<endl;

    return 0;
}