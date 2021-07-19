#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int m;
    cin>>n; 
    cin>>m;
    
    vector<vector<pair<int, int> > > v;
    vector<int> b;
    for(int i = 0; i<n; i++){
        
        vector<pair<int, int> > p_temp;
        v.push_back(p_temp);
        b.push_back(0);
        
    }
    
    for(int i = 0; i<m; i++){
        
        int x; 
        int y;
        int d;
        cin>>x;
        cin>>y;
        cin>>d;
        v[x - 1].push_back(make_pair(y - 1, d));
         
    }
    
    /*for(int i = 0; i<n; i++){
        
        cout<<i + 1<<" -> ";
        for(int j = 0; j<v[i].size(); j++){
            
            cout<<"("<<v[i][j].first + 1<<","<<v[i][j].second<<")"<<" ";
            
        }
        cout<<endl;
        
    }*/
    
    vector<long long int> dist;
    dist.push_back((long long)0);
    for(int i = 1; i<n; i++){
        
        dist.push_back((long long)9000000000000000000);
        
    }
    
    priority_queue <pair<long long int, int>, vector<pair<long long int, int> >, greater<pair<long long int, int> > > pq;
    pq.push({(long long)0, 0});
    
    while(!pq.empty()){
        
        pair<int, int> p = pq.top();
        pq.pop();
        if(b[p.second] == 1){
            
            continue;
            
        } 
        b[p.second] = 1;
        for(int i = 0; i<v[p.second].size(); i++){
            
            pair<int, int> p2 = v[p.second][i];
            if(b[p2.first] == 0){
                
                if(dist[p2.first]>(dist[p.second] + (long long)p2.second)){
                
                    dist[p2.first] = dist[p.second] + (long long)p2.second;
                    pq.push({dist[p2.first], p2.first});
                }
                
            }
            
        }
    
    }
    
    for(int i = 0; i<dist.size(); i++){
        
        cout<<dist[i]<<" ";
        
    }
    cout<<endl;
    
    return 0;
    
}