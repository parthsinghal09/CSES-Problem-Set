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
    
    vector<vector<pair<int, long long int> > > v;
    for(int i = 0; i<n; i++){
        
        vector<pair<int, long long int> > v1;
        v.push_back(v1);
        
    }
    
    for(int i = 0; i<m; i++){
        
        int a; 
        int b;
        long long int c;
        cin>>a;
        cin>>b;
        cin>>c;
        
        v[a - 1].push_back(make_pair((b - 1), c));
        
    }
    
    vector<long long int> d;
    vector<long long int> d_half;
    for(int i = 0; i<n; i++){
        
        d.push_back((long long)(9e18));
        d_half.push_back((long long)(9e18));
        
    }
    
    d[0] = (long long)0;
    d_half[0] = (long long)0;
    
    priority_queue<pair<long long int, pair<int, int> > > pq;
    pq.push(make_pair(d[0], make_pair(0, 0)));
    
    while(!pq.empty()){
        
        pair<long long int, pair<int, int> > p = pq.top();
        pq.pop();
        
        pair<int, int> p1 = p.second;
        int x = p1.first;
        long long int dis = (long long)((-1)*p.first);
        
        if(p1.second == 0){
            
            if(d[x]<dis){
                
                continue;
                
            }
            
        } 
        
        if(p1.second == 1){
            
            if(d_half[x]<dis){
                
                continue;
                
            }
            
        }
        
        for(int i = 0; i<v[x].size(); i++){
            
            pair<int, long long int> p_temp = v[x][i];
            int y = p_temp.first;
            long long int w = p_temp.second;
            
            if(p1.second == 0){
                
                long long int d1 = dis + w;
                long long int d2 = dis + floor(w/((long long)2));
                if(d[y]>d1){
                    
                    d[y] = d1;
                    pq.push(make_pair(((long long)(-1)*d1), make_pair(y, 0)));
                    
                } 
                
                if(d_half[y]>d2){
                    
                    d_half[y] = d2;
                    pq.push(make_pair(((long long)(-1)*d2), make_pair(y, 1)));
                    
                }
                
            } else {
                
                long long int d1 = dis + w;
                if(d_half[y]>d1){
                    
                    d_half[y] = d1;
                    pq.push(make_pair(((long long)(-1)*d1), make_pair(y, 1)));
                    
                } 
                
            }
            
        }
        
    }
    
    /*for(int i = 0; i<d_half.size(); i++){
        
        cout<<d_half[i]<<" ";
        
    }
    cout<<endl;
    
    for(int i = 0; i<d.size(); i++){
        
        cout<<d[i]<<" ";
        
    }
    cout<<endl;*/
    
    
    
    cout<<d_half[n - 1]<<endl;
    
    return 0;
}
