#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    
    long long int d = (long long)1000000007;
    long long int answer = (long long)1;
    for(int i = 0; i<n; i++){
        
        answer = (long long)(answer*((long long)2))%d;
        
    }
    
    answer = (long long)(answer%d);
    cout<<answer<<endl;
    
    return 0;
}