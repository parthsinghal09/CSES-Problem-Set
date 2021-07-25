#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int x;
    cin>>x;
    
    vector<int> price;
    for(int i = 0; i<n; i++){
        
        int h;
        cin>>h;
        price.push_back(h);
        
    }
    
    vector<long long int> pages;
    for(int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        pages.push_back(p);
        
    }
    
    vector<long long int> maxp;
    for(int i = 0; i<=x; i++){
        
        maxp.push_back((long long)0);
        
    }
    
    for(int i = 1; i<=n; i++){
        
        long long int pi = pages[i - 1];
        int ci = price[i - 1];
        for(int j = x; j>=0; j--){
            
            if((j - ci)>=0){
                
                maxp[j] = max(maxp[j], maxp[j - ci] + pi);
                
            }
            
        }
        
    }
    
    /*for(int i = 0; i<=x; i++){
        
        cout<<maxp[i]<<" ";
        
    }
    cout<<endl;*/
    
    cout<<maxp[x]<<endl;

    return 0;
}