#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin>>t;
    
    for(long long int i = (long long)0; i<t; i++){
        
        long long int a;
        long long int b;
        cin>>a;
        cin>>b;
        
        if(a<b){
            
            long long int temp = a;
            a = b;
            b = temp;
            
        }
        
        if((a - 2*b)>(long long)0){
            
            cout<<"NO"<<endl;
            
        } else if((a + b)%3 == 0){
            
            cout<<"YES"<<endl;
            
        } else {
            
            cout<<"NO"<<endl;
            
        }
        
    }
    
    
    
    return 0;
}