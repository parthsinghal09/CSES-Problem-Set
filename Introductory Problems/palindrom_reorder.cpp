#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int len = s.length();
    
    map<char, int> m;
    
    int key_count = 0;
    
    for(int i = 0; i<s.length(); i++){
        
        m[s[i]]++;
        
    }
    
    if(len%2!=0){
        
        map<char, int>::iterator itr;
        int count = 0;
        for (itr = m.begin(); itr!=m.end(); ++itr){
            
            if(itr->second%2!=0){
                
                count = count + 1;
                
            }
            
        }
        if(count>1){
            
            cout<<"NO SOLUTION"<<endl;
            
        } else {
            
            string s1 = "";
            string s2 = "";
            string s3 = "";
            map<char, int>::iterator itr;
            for(itr = m.begin(); itr!=m.end(); ++itr){
                
                if(itr->second%2 == 0){
                    
                    string ss(itr->second/2, itr->first);
                    s1 = s1 + ss;
                    s2 = ss + s2;
                    
                } else {
                    
                    string sss(itr->second, itr->first);
                    s3 = sss;
                    
                }
                
            }
            cout<<(s1 + s3 + s2)<<endl;
            
        }
        
    } else {
        
        map<char, int>::iterator itr;
        string s1 = "";
        string s2 = "";
        int count = 0;
        for(itr = m.begin(); itr!=m.end(); ++itr){
            
            if(itr->second%2!=0){
                
                cout<<"NO SOLUTION"<<endl;
                count = count + 1;
                break;
                
            } else {
                
                string ss(itr->second/2, itr->first);
                s1 = s1 + ss;
                s2 = ss + s2;
                
            }
            
        }
        if(count == 0){
            
            cout<<(s1 + s2)<<endl;
            
        }
        
    }

    return 0;
}


