#include <bits/stdc++.h>
using namespace std;

long long int factorial(long long int n){
    
    if(n == (long long)0){
        
        n = (long long)1;
        
    } else {
        
        n = (long long)(n*factorial(n - (long long)1));
        
    }
    
    return (long long)n;
    
}

string swap_s(string s, int index1, int index2){
    
    char c = s[index1];
    s[index1] = s[index2];
    s[index2] = c;
    
    return s;
    
}

set<string> perm(string s, int begin, int end){
    
    set<string> p;
    if(begin == end){
        
        p.insert(s);
        return p;
        
    } else {
        
        for(int i = begin; i<=end; i++){
            
            s = swap_s(s, begin, i);
            set<string> p1 = perm(s, begin + 1, end);
            set<string>::iterator itr;
            for(itr = p1.begin(); itr!=p1.end(); itr++){
                
                p.insert(*itr);
                
            }
            s = swap_s(s, begin, i);
            
        }
        return p;
    }
    
}

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    
    map<char, int> m;
    
    for(int i = 0; i<n; i++){
        
        m[s[i]]++;
        
    }
    
    long long int k = factorial(n);
    map<char, int>::iterator itr;
    for(itr = m.begin(); itr!=m.end(); ++itr){
        
        k = k/(factorial(((long long)itr->second)));
        
    }
    
    cout<<k<<endl;
    
    set<string> pp = perm(s, 0, n - 1);
    set<string>::iterator itr1;
    for(itr1 = pp.begin(); itr1!=pp.end(); itr1++){
        
        cout<<(*itr1)<<endl;
        
    }
    return 0;
    
}