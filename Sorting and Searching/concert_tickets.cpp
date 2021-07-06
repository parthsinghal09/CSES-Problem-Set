#include <bits/stdc++.h> // for lower_bound, upper_bound and sort
using namespace std;

int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    
    multiset<long long int, greater<int>> m1;
    for(int i = 0; i<n; i++){
        
        long long int p1;
        cin>>p1;
        m1.insert(p1);
        
    }
    
    vector<long long int> v2;
    for(int i = 0; i<m; i++){
        
        long long int p2;
        cin>>p2;
        v2.push_back(p2);
        
    }
    
    for(int i = 0; i<m; i++){
        
        auto itr = m1.lower_bound(v2[i]);
        if(itr!=m1.end()){
            
            if(*itr == v2[i]){
                
                cout<<*itr<<endl;
                m1.erase(itr);
                
            } else {
                
                auto itr1 = itr--;
                if(itr1!=m1.end()){
                    
                    cout<<*itr1<<endl;
                    m1.erase(itr1);
                    
                } else {
                    
                    cout<<-1<<endl;
                    
                }
                
            }
            
        } else {
            
            cout<<-1<<endl;
            
        }
        
    }

	return 0;
}