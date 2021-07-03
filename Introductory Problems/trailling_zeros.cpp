#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    
    long long int t = n;
    
    long long int count2 = (long long)0;
    
    while(t!=0){
        
        t = (long long)floor(t/((long long)2));
        count2 = count2 + t;
        
    }
    
    t = n;
    
    long long int count5 = (long long)0;
    
    while(t!=0){
        
        t = (long long)floor(t/((long long)5));
        count5 = count5 + t;
        
    }
    
    long long int power = min(count2, count5);
    cout<<power<<endl;
    
    return 0;
}