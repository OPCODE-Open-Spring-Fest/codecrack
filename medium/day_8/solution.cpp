//Write your code here
// Code by Jagpreet153
#include <bits/stdc++.h>
using namespace std;
const int P = 131;
typedef long long ll;
ll h[10010], p[10010];
int n;
string s;
pair<bool, int> check(int mid) {
    unordered_map<ll, int> M;
    for (int i = mid; i <= n; i++) {
        ll hash = h[i] - h[i - mid] * p[mid];
        if (M.count(hash)) return make_pair(true, M[hash]);
        M[hash] = i - mid + 1;
    }
    return make_pair(false, -1);
}

int main() {
    cin >> s;
    s = " " + s;
    n = s.size() - 1;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] * P + s[i];
        p[i] = p[i - 1] * P;
    }
    int l = 0, r = n, start = -1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        pair<bool, int> result = check(mid);
        if (result.first) l = mid, start = result.second;
        else r = mid - 1;
    }
    for (int i = start; i < start + l; i++) cout << s[i];
    return 0;
}