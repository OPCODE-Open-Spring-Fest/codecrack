//write your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long int


 

const int N = 1e5 + 10;
const int mod = 1e9 + 7;
 
int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        (b >>= 1)%mod;
    }
    return res%mod;
}

void solve()
{ 
    int n;
		cin>>n;
		int k;
		cin>>k;
		int chk = power(n,k)%mod;
		int ans = chk%mod;
		cout<<ans<<endl;
}


    
        


signed main() 
{
	int t;
	cin>>t;
    // cout<<t<<endl;
	while(t--)
    {
        solve();   
    }
	return 0;
}

  