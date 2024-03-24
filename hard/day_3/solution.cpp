//Write your code here
// HARE RAM HARE KRISHNA

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second
#define readyplayerone()                  \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }

#define couty cout << "YES" << endl
#define coutn cout << "NO" << endl
#define cout(a) cout << a << endl

#define min3(a, b, c) (a < b && a < c) ? a : (b < c) ? b \
                                                     : c
#define max3(a, b, c) (a > b && a > c) ? a : (b > c) ? b \
                                                     : c

#define fi(i, s, e) for (int i = s; i < e; i++)
#define fd(i, s, e) for (int i = s; i > e; i--)

#define ain(i, arr, n)          \
    ;                           \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> arr[i];          \
    }
#define aout(i, arr, n)         \
    ;                           \
    for (int i = 0; i < n; i++) \
    {                           \
        cout << arr[i] << "\t"; \
    }

int solve(int x){
    int res = 0;
    while(x){
        x >>= 1;
        res += x;
    }
    return res;
}

int32_t main(){
    int n, k, x, res=0;
    cin>>n;
    k = solve(n-1);
    for(int i = 0; i < n; i++){
        cin>>x;
        int a = solve(i);
        int b = solve(n-i-1);
        if(k - a - b == 0)
            res ^= x;
    }
    cout(res);
}