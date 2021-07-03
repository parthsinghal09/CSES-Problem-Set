#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; 
    cin>>s;
    long long int max1 = (long long)1;
    long long int max2 = (long long)1;
    
    for(int i = 1; i<s.length(); i++){
        
        if(s[i] == s[i - 1]){
            
            max1 = (long long)(max1 + 1);
            max2 = max(max1, max2);
            
        } else {
            
            max1 = (long long)1;
            
        }
        
    }
    
    cout<<max2<<endl;
    
    return 0;
    
}