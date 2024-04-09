//write your code here
#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ldouble long long double

void solve(){
	int n,x;  cin>>n>>x;
	int mn = n, mx = 1e19;
	for (int i = 0; i < 64; i++){
		int bit = 1LL<<i;
		if(!(n&bit) && (x&bit)){
			cout<<-1<<endl;
			return;
		}
		if((n&bit) && (x&bit)){
			mx = min(mx, ((x>>i)<<i) + bit - 1);
		}
		if((n&bit) && !(x&bit)){
			mn = max(mn, ((n>>i)<<i) + bit);
		}
	}
	if(mx < mn) cout<<-1<<endl;
	else cout<<mn<<endl;
}
signed main(){
    
    int t;  cin>>t;
    while(t--){
		solve();
	}
    return 0;
}