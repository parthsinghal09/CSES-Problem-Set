#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        
        long long int y; //row
        long long int x; //column
        cin>>y;
        cin>>x;
        if(y == x){
            
            cout<<((long long)(y*y - x + (long long)1))<<endl;
            
        } else if(y>x){
            
            if(y%2 == 0){
                
                cout<<((long long)(y*y - x + (long long)1))<<endl;
                
            } else {
                
                cout<<((long long)(((y - (long long)1)*(y - (long long)1)) + x))<<endl;
                
            }
            
        } else if(x>y){
            
            if(x%2 == 0){
                
                cout<<((long long)(((x - (long long)1)*(x - (long long)1)) + y))<<endl;
                
            } else {
                
                cout<<((long long)(x*x - y + (long long)1))<<endl;
                
            }
            
        }
            
    }
    
    return 0;
    
}