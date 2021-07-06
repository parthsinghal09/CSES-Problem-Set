#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<long long int> v;
    for(int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        v.push_back(p);
        
    }
    
    long long int maxs = (long long)(-9000000000000000000);
    long long int sums = (long long)0;
    
    for(int i = 0; i<n; i++){
        
        sums = max(v[i], sums + v[i]);
        maxs = max(maxs, sums);
        
    }
    
    cout<<maxs<<endl;

    return 0;
}