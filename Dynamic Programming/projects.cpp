#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n; 
    
    multimap<int, pair<int, long long int> > mp;
    for(int i = 0; i<n; i++){
        
        int s;
        int e;
        long long int r;
        cin>>s;
        cin>>e;
        cin>>r;
        
        if(mp.find(e) == mp.end()){
        
            pair<int, long long int> pin = make_pair(s, r);
            mp.insert(pair<int, pair<int, long long int> >(e, pin));
            
        } else {
            
            auto itr = mp.find(e);
            pair<int, long long int> pin = itr->second;
            if(pin.first == s){
                    
                if(pin.second<r){
                    
                    pin.second = r;
                    
                }
                    
            } else {
                
                pair<int, long long int> pin = make_pair(s, r);
                mp.insert(pair<int, pair<int, long long int> >(e, pin));
                
            }
            
        }
        
    }
    
    /*for(auto d : mp){
        
        pair<int, long long int> pp = d.second;  
        cout<<d.first<<" "<<pp.first<<" "<<pp.second<<endl;
        
    }*/
    
    vector<long long int> dp;
    
    for(int i = 0; i<mp.size(); i++){
        
        dp.push_back((long long)0);
        
    }
    
    map<int, int> mp2;
    int j = 0;
    for(auto d1 : mp){
        
        pair<int, long long int> ptemp = d1.second;
        mp2[ptemp.first] = j;
        j++;
        
    }
    
    int i = 0;
    
    /*for(auto d : mp){
        
        pair<int, long long int> pp = d.second;  
        cout<<d.first<<" "<<pp.first<<" "<<pp.second<<endl;
        
    }*/
    
    /*for(auto d : mp2){
        
        cout<<d.first<<" "<<d.second<<endl;
        
    }*/
    
    for(auto d : mp){
        
        pair<int, long long int> pd = d.second;
        if(i == 0){
            
            dp[i] = pd.second;
            i++;
            
        } else {
            
            auto itr = mp.lower_bound(pd.first);
            if(itr!=mp.begin()){
                
                itr--;
                
            }
            pair<int, int> p = itr->second;
            
            if(pd.first<=(itr->first)){
                    
                dp[i] = max(dp[i - 1], pd.second);
                i++;
                    
            } else {
                    
                int index = mp2[p.first];
                dp[i] = max(dp[i - 1], pd.second + dp[index]);
                i++;
                    
            }
            
        }
        
    }
    
    /*for(int i = 0; i<dp.size(); i++){
        
        cout<<dp[i]<<" ";
        
    }
    cout<<endl;*/
    cout<<dp[dp.size() - 1]<<endl;

    return 0;
}