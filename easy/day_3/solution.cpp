// Write your solution here
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a ;
    cin>>a;
    while(a--){
        int n ;
        cin>>n;
        vector<int> p(n) , q(n);
        for(int j = 0 ; j<n ; j++){
            cin>>p[j];
        }
        for(int j = 0 ;j<n ; j++){
            cin>>q[j];
        }
        unordered_map <int ,int> l;
        for(int j = 0 ;j<n ;j++){
            l[p[j]]++;
            l[q[j]]++;
        }
        int curr = 0;
        int maxl = 0;
      for (auto& entry : l) {
        curr = max(curr, entry.second);
        maxl = max(maxl, entry.second);
    }
    cout<<maxl<<endl;
    }
    return 0;
}
