#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long int mod = (long long)(1e9 + 7);
    
    int n;
    int m;
    cin>>n;
    cin>>m;
    
    vector<vector<int> > v;
    vector<long long int> d;
    vector<int> indegree;
    for(int i = 0; i<n; i++){
        
        vector<int> v1;
        v.push_back(v1);
        d.push_back((long long)0);
        indegree.push_back(0);
    }
    
    d[0] = (long long)1;
    
    for(int i = 0; i<m; i++){
        
        int a;
        int b;
        cin>>a;
        cin>>b;
        v[a - 1].push_back(b - 1);
        indegree[b - 1]++;
        
    }
    
    queue<int> p;
    for(int i = 1; i<n; i++){
        
        if(indegree[i] == 0){
            
            p.push(i);
            
        }
        
    }
    
    while(!p.empty()){
        
        int x = p.front();
        p.pop();
        
        for(int i = 0; i<v[x].size(); i++){
            
            int temp = v[x][i];
            indegree[temp] = indegree[temp] - 1;
            if(indegree[temp] == 0){
                
                p.push(temp);
                
            }
            
        }
        
    }
    
    queue<int> q;
    q.push(0);
    
    while(!q.empty()){
        
        int x = q.front();
        q.pop();
        
        for(int i = 0; i<v[x].size(); i++){
            
            int temp = v[x][i];
            if(indegree[temp]>0){
                
                d[temp] = d[temp] + d[x]%mod;
                indegree[temp] = indegree[temp] - 1;
                if(indegree[temp] == 0){
                    
                    q.push(temp);
                    
                }
                
            }
            
        }
        
    }
    
    cout<<d[n - 1]%mod<<endl;


    return 0;
}