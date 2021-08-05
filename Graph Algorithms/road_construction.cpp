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
    
    vector<pair<int, int> > v;
    for(int i = 0; i<m; i++){
        
        int a;
        int b;
        cin>>a;
        cin>>b;
        a = a - 1;
        b = b - 1;
        v.push_back(make_pair(a, b));
        
    }
    
    vector<int> link;
    vector<long long int> size;
    for(int i = 0; i<n; i++){
        
        link.push_back(i);
        size.push_back((long long)1);
        
    }
    
    int count = n;
    long long mst = (long long)0;
    for(int i = 0; i<m; i++){
        
        pair<int, int> p = v[i];
        int x = p.first;
        int y = p.second;
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
            mst = max(mst, size[x1]);
            cout<<count<<" "<<mst<<endl;
            
        } else {
            
            cout<<count<<" "<<mst<<endl;
            
        }
        
    }
    

    return 0;
}