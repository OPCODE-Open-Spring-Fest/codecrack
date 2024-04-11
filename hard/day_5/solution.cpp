//Write your code here
// LUOGU_RID: 147799314
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 5e5 + 5;

ll a[MAXN], dif[MAXN];
map<int, ll> mp;
int l_[MAXN], r_[MAXN]; ll x_[MAXN];

int main() { ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 0;
        int q; cin >> q; for (int i = 1; i <= q; i++) {
            int l, r; ll x; cin >> l >> r >> x; l_[i] = l; r_[i] = r, x_[i] = x;
            mp[l] += x;
            if (r+1 <= n)
                mp[r+1] -= x;
            while (!mp.empty() && mp.begin()->second == 0)
                mp.erase(mp.begin());
            if (!mp.empty() && mp.begin()->second < 0) {
                ans = i;
                mp.clear();
            }
        }
        for (int i = 1; i <= ans; i++) {
            int l = l_[i], r = r_[i]; ll x = x_[i];
            dif[l] += x;
            if (r+1 <= n)
                dif[r+1] -= x;
        }
        for (int i = 1; i <= n; i++) {
            dif[i] += dif[i-1];
            a[i] += dif[i];
            cout << a[i] << " \n"[i == n];
        }

        // init
        for (int i = 1; i <= n; i++)
            dif[i] = 0;
        mp.clear();
    }
    return 0;
}