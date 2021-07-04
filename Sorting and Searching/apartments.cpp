#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int n; 
    int m;
    long long int k;
    cin>>n;
    cin>>m;
    cin>>k;
    
    vector<long long int> a;
    vector<long long int> b;
    
    for(int i = 0; i<n; i++){
        
        long long int p1;
        cin>>p1;
        a.push_back(p1);
        
    }
    
    for(int i = 0; i<m; i++){
        
        long long int p2;
        cin>>p2;
        b.push_back(p2);
        
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int count = 0;
    int j = 0;
    for(int i = 0; i<m; i++){
        
        while(j<n){
            
            if((a[j] - k)>b[i]){
                
                break;
                
            } else if((a[j] + k)<b[i]){
                
                j++;
                
            } else {
                
                count = count + 1;
                j++;
                break;
                
            }
            
        }
        
    }
    
    cout<<count<<endl;
    
    
    return 0;
}