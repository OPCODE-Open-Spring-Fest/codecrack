//Write your code here
#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        for(int i=0;i<n-1;i++){
            if(v[i]==1){
                v[i]++;
            }
            if(v[i+1]==1){
                v[i+1]+=2;
            }
            else if(v[i+1]%v[i]==0){
                v[i+1]++;
            }
        }
        if(v[n-1]%v[n-2]==0){
            v[n-1]++;
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}