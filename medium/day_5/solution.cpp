//Write your code here
#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int n , sum=0;
    cin>>n;
    vector<int> a(n) , ans;
    for(int i=0; i<n; i++) {cin>>a[i]; sum += a[i];}
    for(int i=0; i<n; i++){
        int k = sum - a[i];
        for(int j=0; j<n; j++){
            if(j!=i && 2*(a[j]) == k){
                ans.push_back(i+1);
                break;
            }
        }
    }
    if(ans.size()){
        cout<<ans.size()<<endl;
        for(auto it : ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<0<<endl;
    }
}