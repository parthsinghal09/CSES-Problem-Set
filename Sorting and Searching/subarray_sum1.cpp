#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
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
    
    int i = 0; 
    int j = 0;
    long long int sums = (long long)0;
    int count = 0; 
    while(i!=n){
        
        if(j<n){
            
            sums = sums + v[j];        
            if(sums>=x){
                
                if(sums == x){
                    
                    count = count + 1;
                    
                }
                sums = sums - v[i] - v[j];
                i++;
                if(j == n){
                    
                    i--;
                    sums = sums + v[i];
                    
                }
                
            } else {
                
                j++;
                
            }
            
        } else {
            
            sums = sums - v[i];
            if(sums == x){
                
                count = count + 1;
                
            }
            i++;
            
        }
        
    }
    
    cout<<count<<endl;

    return 0;
}