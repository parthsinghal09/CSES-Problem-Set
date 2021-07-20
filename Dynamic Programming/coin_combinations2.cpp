#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int x; 
    cin>>x;

    long long int mod = 1000000007;
    
    vector<int> coins;
    for(int i = 0; i<n; i++){
        
        int c;
        cin>>c;
        coins.push_back(c);
        
    }
    
    vector<long long int> solve;
    solve.push_back((long long)1);
    for(int i = 1; i<=x; i++){
        
        solve.push_back(0);
        
    }
        
    for(int i = 0; i<n; i++){
        
        for(int j = 0; j<=x; j++){
            
            if(j - coins[i]>=0){
                
                solve[j] = solve[j] + solve[j - coins[i]]%mod;
                
            }
            
        }
        
    }
    
    cout<<solve[x]%mod<<endl;

    return 0;
}