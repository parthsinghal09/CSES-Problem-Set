#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    long long int mod = 1000000007;
    
    vector<long long int> solve;
    solve.push_back((long long)1);
    for(int i = 1; i<=n; i++){
        
        solve.push_back((long long)0);
        
    }
    
    for(int i = 1; i<=n; i++){
        
        long long int a = (long long)0;
        for(int j = 1; j<=6; j++){
            
            if(j<=i){
                
                a = a + solve[i - j];
                
            } else{
                
                break;
                
            }
            
        }
        
        solve[i] = a%mod;
        
    }
    
    cout<<solve[n]<<endl;

    return 0;
}