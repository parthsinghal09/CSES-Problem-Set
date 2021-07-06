#include <bits/stdc++.h>
using namespace std;

bool as_second(const pair<long long int, int> &p1, const pair<long long int, long long int> &p2)
{
    
    return (p1.second<p2.second);
    
}

int main()
{
    int n;
    cin>>n;
    
    vector<pair<long long int, long long int>> v;
    
    for(int i = 0; i<n; i++){
        
        long long int a;
        long long int b;
        cin>>a;
        cin>>b;
        v.push_back(make_pair(a, b));
        
    }
    
    sort(v.begin(), v.end(), as_second);
    
    int count = 0;
    long long int prev = 0; 
    
    for(int i = 0; i<n; i++){
        
        if(v[i].first>=prev){
            
            count++;
            prev = v[i].second;
            
        }
        
    }
    
    cout<<count<<endl;

    return 0;
}

