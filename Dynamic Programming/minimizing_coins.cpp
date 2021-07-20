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
    
    vector<int> coins;
    for(int i = 0; i<n; i++){
        
        int c;
        cin>>c;
        coins.push_back(c);
        
    }
    
    vector<long long int> solve;
    solve.push_back((long long)0);
    for(int i = 1; i<=x; i++){
        
        solve.push_back((long long)0);
        
    }
    
    for(int i = 1; i<=x; i++){
        
        long long int minc = 9000000000000000000;
        for(int j = 0; j<n; j++){
            
            if(coins[j]<=i){
                
                minc = min(minc,  solve[i - coins[j]] + 1);
                
            }
            
        }
        
        solve[i] = minc;
        
    }
    
    /*for(int i = 0; i<=x; i++){
     
        cout<<solve[i]<<" "; 
        
    }
    cout<<endl;*/

    if(solve[x] == 9000000000000000000){
        
        cout<<-1<<endl;
        
    } else {
        
        cout<<solve[x]<<endl;
        
    }

    return 0;
}