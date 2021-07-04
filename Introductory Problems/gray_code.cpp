#include <bits/stdc++.h>
using namespace std;

vector<string> gray(int n){
    
    vector<string> v;
    if(n == 1){
        
        v.push_back("0");
        v.push_back("1");
        return v;
        
    } else if(n == 2){
        
        v.push_back("00");
        v.push_back("01");
        v.push_back("11");
        v.push_back("10");
        return v;
        
    } else {
        
        vector<string> v1 = gray(n - 1);
        vector<string> v2;
        for(int i = (v1.size() - 1); i>=0; i--){
            
            v2.push_back("1" + v1[i]);
            v1[i] = "0" + v1[i];
            
        }
        
        for(int i = 0; i<v1.size(); i++){
            
            v.push_back(v1[i]);
            
        }
        
        for(int i = 0; i<v2.size(); i++){
            
            v.push_back(v2[i]);
            
        }
        
        return v;
        
    }
    
}

int main()
{
    
    int n;
    cin>>n;
    
    vector<string> v = gray(n);
    
    for(int i = 0; i<v.size(); i++){
        
        cout<<v[i]<<endl;
        
    }
    
    return 0;
}