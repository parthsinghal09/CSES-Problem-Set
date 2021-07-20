#include <bits/stdc++.h>
using namespace std;

vector<int> get_digits(int a){
    
    vector<int> v1;
    while(a!=0){
        
        int r = a%10;
        v1.push_back(r);
        a = a/10;
        
    }
    
    vector<int> v;
    
    for(int i = (v1.size() - 1); i>=0; i--){
        
        v.push_back(v1[i]);
        
    }
    
    return v;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<long long int> solve;
    for(int i = 0; i<=9; i++){
        
        solve.push_back((long long)1);
        
    }
    
    for(int i = 10; i<=n; i++){
        
        solve.push_back((long long)0);
        
    }
    
    if(n>9){
        
        for(int i = 10; i<=n; i++){
            
            vector<int> digits = get_digits(i);
            long long int minc = 9e18;
            for(int j = 0; j<digits.size(); j++){
                
                if((i - digits[j])>=0 && digits[j]!=0){
                
                    minc = min(minc, solve[i - digits[j]] + 1);
                    
                }
            }
            
            solve[i] = minc;
            
        }
        
        cout<<solve[n]<<endl;
        
    } else {
        
        cout<<1<<endl;
        
    }

    return 0;
}