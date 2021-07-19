#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long int x;
    cin>>n;
    cin>>x;
    
    vector<long long int> v;

    for(int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        v.push_back(p);
        
    }
    
    sort(v.begin(), v.end());
    
    int i = 0;
    int j = (n - 1);
    
    int count = 0;
    
    while(i<=j){
        
        if((v[i] + v[j])>x){
                
            j = j - 1; 
            count = count + 1;
            
        } else {
            
            i = i + 1;
            j = j - 1;
            count = count + 1;
            
        }
        
    }
    
    cout<<count<<endl;

    return 0;
}
