#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int n;
    cin>>n; 
    
    map<long long int, string> m;
    
    for(int i = 0; i<n; i++){
        
        long long int a;
        long long int b;
        cin>>a;
        cin>>b;
        m[a] = "arrival";
        m[b] = "departure";
        
    }

    int count = 0; 
    int maxc = -1;
    for(auto x : m){
        
        if(x.second == "arrival"){
            
            count++;
            
        } else {
            
            count--;
            
        }
        maxc = max(maxc, count);
        
    }
    
    cout<<maxc<<endl;

	return 0;
}