#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    
    long long int sum = 0;
    
    for(int i = 0; i<(n - 1); i++){
        
        long long int k;
        cin>>k;
        sum = sum + k;
        
    }
    
    long long int missn = (long long)((long long)(n*(n + 1)/2) - sum);
    cout<<missn<<endl;
    
    return 0;
    
}