#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    if(n<=(long long)3 && n!=1){
        
        cout<<"NO SOLUTION"<<endl;
        
    } else {
        
        vector<long long int> v1;
        vector<long long int> v2;
        
        for(long long int i = 1; i<=n; i++){
            
            if(i%2 == 0){
                
                v1.push_back(i);
                
            } else {
                
                v2.push_back(i);
                
            }
            
        }
        
        vector<long long int> v;
        for(long long int i = 0; i<v1.size(); i++){
            
            v.push_back(v1[i]);
            
        }
        for(long long int i = 0; i<v2.size(); i++){
            
            v.push_back(v2[i]);
            
        }
        for(long long int i = 0; i<v.size(); i++){
            
            cout<<v[i]<<" ";
            
        }
        cout<<endl;
        
    }
    
    return 0;
    
}