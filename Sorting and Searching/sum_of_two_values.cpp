#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    long long int x;
    cin>>n;
    cin>>x;
    
    vector<pair<long long int, int> > v;
    for(int i = 0; i<n; i++){
        
        long long int p; 
        cin>>p;
        v.push_back(make_pair(p, i));
        
    }
    
    sort(v.begin(), v.end());
    
    int i = 0; 
    int j = n - 1;
    while(i<j){
        
        if((v[i].first + v[j].first) == x){
            
            cout<<(v[i].second + 1)<<" "<<(v[j].second + 1)<<endl;
            break;
            
        } else if((v[i].first + v[j].first)<x){
            
            i++;
            
        } else if((v[i].first + v[j].first)>x){
            
            j--;
            
        }
        
    }
    
    if(i>=j){
        
        cout<<"IMPOSSIBLE"<<endl;
        
    }

	return 0;
}