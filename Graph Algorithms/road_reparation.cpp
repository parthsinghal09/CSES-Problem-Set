#include <bits/stdc++.h>
using namespace std;

int find(int n, vector<int>& l){
    
    if(n == l[n]){
        
        return n;
        
    } else {
        
        return l[n] = find(l[n], l);
        
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int m;
    cin>>n;
    cin>>m;
    
    vector<pair<long long int, pair<int, int> > > v;
    for(int i = 0; i<m; i++){
        
        int a;
        int b;
        long long int c;
        cin>>a;
        cin>>b;
        cin>>c;
        a = a - 1;
        b = b - 1;
        v.push_back(make_pair(c, make_pair(a, b)));
        
    }
    sort(v.begin(), v.end());
    
    vector<int> link;
    vector<int> size;
    for(int i = 0; i<n; i++){
        
        link.push_back(i);
        size.push_back(1);
        
    }
    
    long long int mst = (long long)0;
    int count = n;
    for(int i = 0; i<m; i++){
        
        pair<long long int, pair<int, int> > p = v[i];
        long long int w = p.first;
        pair<int, int> p1 = p.second;
        int x = p1.first;
        int y = p1.second;
        int x1 = find(x, link);
        int y1 = find(y, link);
        if(x1!=y1){
            
            if(size[x1]<size[y1]){
                
                int temp = x1;
                x1 = y1;
                y1 = temp;
                
            } 
            
            link[y1] = x1;
            count--;
            size[x1] = size[x1] + size[y1];
            mst = mst + w;
            
        }
        
    }
    
    
    if(count == 1){
        
        cout<<mst<<endl;
        
    } else {
        
        cout<<"IMPOSSIBLE"<<endl;
        
    }
    

    return 0;
}