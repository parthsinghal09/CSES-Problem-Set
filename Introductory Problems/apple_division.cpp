#include <bits/stdc++.h>
using namespace std;



int main()
{
    
    int n;
    cin>>n;
    
    vector<long long int> v;
    long long int sum = (long long)0;
    for(int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        v.push_back(p);
        sum = sum + p;
        
    }
    
    long long int mins = (long long)sum;
    
    for(int i = 0; i<(1<<n); i++){
        
        long long int subs = (long long)0;
        
        for(int j = 0; j<n; j++){
            
            if((i&(1<<j))!=0){
            
                subs = subs + v[j];
                
            }
            
        }
        
        mins = min(mins, abs(sum - (long long)2*subs));
        
    }
    
    cout<<mins<<endl;
    
    return 0;
}