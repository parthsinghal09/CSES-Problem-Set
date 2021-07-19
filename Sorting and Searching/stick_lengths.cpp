#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<long long int> v;
    for(int i = 0; i<n; i++){
        
        long long int p;
        cin>>p;
        v.push_back(p);
        
    }
    
    sort(v.begin(), v.end());
    
    if(v.size()%2!=0){
        
        long long int a = v[(v.size() - 1)/2];
        long long int sum = (long long)0;
        for(int i = 0; i<v.size(); i++){
            
            sum = sum + abs(a - v[i]);
            
        } 
        cout<<sum<<endl;
        
    } else if(v.size()%2 == 0){
        
        long long int a = v[(v.size() - 1)/2];
        long long int b = v[v.size()/2];
        long long int sum1 = (long long)0;
        long long int sum2 = (long long)0;
        for(int i = 0; i<v.size(); i++){
            
            sum1 = sum1 + abs(a - v[i]);
            sum2 = sum2 + abs(b - v[i]);
            
        } 
        cout<<min(sum1, sum2)<<endl;
        
    }

    return 0;
}