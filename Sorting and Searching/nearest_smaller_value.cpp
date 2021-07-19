#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    vector<long long int> v;
    for(int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        v.push_back(p);
        
    }
    
    stack<pair<long long int, int>> s;
    s.push(make_pair(v[0], 1));
    cout<<0<<" ";
    
    for(int i = 1; i<n; i++){
        
        while(!s.empty()){
            
            pair<long long int, int> p1 = s.top();
            if(p1.first<v[i]){
                
                cout<<p1.second<<" ";
                s.push(make_pair(v[i], i + 1));
                break;
                
            } else {
                
                s.pop();
                
            }
            
        }
        
        if(s.empty()){
            
            cout<<0<<" ";
            s.push(make_pair(v[i], i + 1));
            
        }
        
    }
    
    cout<<endl;

    return 0;
}
