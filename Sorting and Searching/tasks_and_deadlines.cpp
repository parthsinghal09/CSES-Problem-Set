#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<pair<int, int>> v;
    for(int i = 0; i<n; i++){
        
        long long int a;
        cin>>a;
        long long int d; 
        cin>>d;
        v.push_back(make_pair(a, d));
        
    }
    
    sort(v.begin(), v.end());
    
    long long int r = (long long)(v[0].second - v[0].first);
    long long int t = (long long)v[0].first;
    
    for(int i = 1; i<n; i++){
        
        t = t + (long long)v[i].first;
        r = r + (long long)(v[i].second - t);
        
    }
    
    cout<<r<<endl;
    
    return 0;
}