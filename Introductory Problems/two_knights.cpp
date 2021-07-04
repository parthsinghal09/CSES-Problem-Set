#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    
    for(long long int i = 1; i<=n; i++){
        
        long long int total = (long long)(i*i*(i*i - (long long)1))/((long long)2);
        long long int intersect = (long long)((long long)4*(i - (long long)1)*(i - (long long)2));
        cout<<((long long)(total - intersect))<<endl;
        
    }
    return 0;
}