#include <bits/stdc++.h>
using namespace std;

string toh(int nod, string a, string b, string c){
    
    if(nod == 1){
        
        string s = a + " " + c + "-"; 
        
        return s;
        
    } else {
        
        string ss = "";
        ss = ss + toh((nod - 1), a, c, b);
        ss = ss + a + " " + c + "-";
        ss = ss + toh((nod - 1), b, a, c);
        
        return ss;
        
    }
    
}

int main()
{
    int k; 
    cin>>k;
    
    string a = "1";
    string b = "2";
    string c = "3";
    
    string ans = toh(k, a, b, c);
    
    vector<string> vs;
    
    string temp = "";
    
    for(int i = 0; i<ans.length(); i++){
        
        if(ans[i] == '-'){
            
            vs.push_back(temp);
            temp = "";
            
        } else {
            
            temp = temp + ans[i];
            
        }
        
    }
    
    cout<<vs.size()<<endl;
    
    for(int i = 0; i<vs.size(); i++){
        
        cout<<vs[i]<<endl;
        
    }

    return 0;
}