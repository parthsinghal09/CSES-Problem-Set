#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    
    long long int total = (long long)(n*(n + (long long)1));
    
    if(total%4!=0){
        
        cout<<"NO"<<endl;
        
    } else {
        
        if((n%2)%2 == 0){
            
            cout<<"YES"<<endl;
            cout<<((long long)(n/((long long)2)))<<endl;
            long long int s = (long long)((n/((long long)2))/((long long)2));
            long long int j;
            for(long long int i = (long long)1; i<=s; i++){
                
                cout<<i<<" ";
                j = i;
                
            }
            for(long long int i = n; i>=(n - s + 1); i--){
                
                cout<<i<<" ";
                
            }
            cout<<endl;
            cout<<((long long)(n/((long long)2)))<<endl;
            for(long long int i = j + 1; i<=(n - s); i++){
                
                cout<<i<<" ";
                
            }
            cout<<endl;
            
        } else {
            
            vector<long long int> vv1; 
            vv1.push_back(1);
            vv1.push_back(2);
            vector<long long int> vv2;
            vv2.push_back(3);
            cout<<"YES"<<endl;
            if(n == (long long)3){
                
                cout<<vv1.size()<<endl;
                for(int i = 0; i<vv1.size(); i++){
                    
                    cout<<vv1[i]<<" ";
                    
                }
                cout<<endl;
                cout<<vv2.size()<<endl;
                for(int i = 0; i<vv2.size(); i++){
                    
                    cout<<vv2[i]<<" ";
                    
                }
                cout<<endl;
                
            } else {
                
                for(long long int i = 4; i<=n; i = (i + (long long)4)){
                    
                    vv1.push_back(i);
                    vv1.push_back(i + (long long)3);
                    vv2.push_back(i + (long long)1);
                    vv2.push_back(i + (long long)2);
                    
                }
                cout<<vv1.size()<<endl;
                for(int i = 0; i<vv1.size(); i++){
                    
                    cout<<vv1[i]<<" ";
                    
                }
                cout<<endl;
                cout<<vv2.size()<<endl;
                for(int i = 0; i<vv2.size(); i++){
                    
                    cout<<vv2[i]<<" ";
                    
                }
                cout<<endl;
                
            }
            
        }
        
    }
    
    return 0;
}