#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    int n;
    cin>>x>>n;
    
    set<int> s;
    s.insert(0);
    s.insert(x);
    
    multiset<int> m;
    m.insert(x);
    
    for(int i = 0; i<n; i++){
        
        int p; 
        cin>>p;
        auto upper = s.lower_bound(p);
        int b = *upper - p;
        upper--;
        int a = p - *upper;
        m.erase(m.find(a + b));
        m.insert(a);
        m.insert(b);
        cout<<*m.rbegin()<<" ";
        s.insert(p);
        
    }

    return 0;
}