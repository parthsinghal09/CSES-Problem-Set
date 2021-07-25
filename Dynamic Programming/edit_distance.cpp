#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a;
    string b;
    cin>>a;
    cin>>b;
    
    vector<vector<long long int> > dp;
    if(a.length()>b.length()){
        
        for(int i = 0; i<2; i++){
            
            vector<long long int> v;
            for(int j = 0; j<=b.length(); j++){
                
                v.push_back((long long)0);
                
            } 
            dp.push_back(v);
            
        }
        
        for(int i = 0; i<=a.length(); i++){
            
            for(int j = 0; j<=b.length(); j++){
                
                if(i == 0){
                    
                    dp[i%2][j] = j;
                    
                } else {
                    
                    if(j == 0){
                        
                        dp[i%2][j] = i;
                        
                    } else {
                        
                        if(a[i - 1] == b[j - 1]){
                            
                            dp[i%2][j] = dp[(i - 1)%2][j - 1];
                            
                        } else {
                            
                            dp[i%2][j] = 1 + min(dp[(i - 1)%2][j - 1], min(dp[(i - 1)%2][j], dp[i%2][j - 1]));
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
        cout<<dp[a.length()%2][b.length()]<<endl;
        
    } else {
        
        for(int i = 0; i<2; i++){
            
            vector<long long int> v;
            for(int j = 0; j<=a.length(); j++){
                
                v.push_back((long long)0);
                
            } 
            dp.push_back(v);
            
        }
        
        for(int i = 0; i<=b.length(); i++){
            
            for(int j = 0; j<=a.length(); j++){
                
                if(i == 0){
                    
                    dp[i%2][j] = j;
                    
                } else {
                    
                    if(j == 0){
                        
                        dp[i%2][j] = i;
                        
                    } else {
                        
                        if(b[i - 1] == a[j - 1]){
                            
                            dp[i%2][j] = dp[(i - 1)%2][j - 1];
                            
                        } else {
                            
                            dp[i%2][j] = 1 + min(dp[(i - 1)%2][j - 1], min(dp[(i - 1)%2][j], dp[i%2][j - 1]));
                            
                        }
                        
                    }
                    
                }
                
            }
            
        }
        
        cout<<dp[b.length()%2][a.length()]<<endl;
        
    }

    return 0;
}