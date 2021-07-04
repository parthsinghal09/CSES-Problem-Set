#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    
    while(1 == 1){

        cout<<n<<" ";
        
        if(n == 1){
            
            break;
            
        } else {
            
            if(n%2 == 0){
                
                n = (long long)(n/2);
                
            } else {
                
                n = (long long)(3*n + 1);
                
            }
        
        }
        
    }
    
    return 0;
    
}