//Write your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define INF (int)1e18
#define f first
#define s second
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
// maintain maximum and minimum among the activated stuff 
// find maximum, and then deactivate all != maximum
 
struct node{
    ll mn, mx, lz;
};
 
const int N = 5e5 + 69;
int n, q, a[N], l[N], r[N], d[N];
ll diff[N];
vector <int> b[N];
node seg[4 * N];
 
void updlz(int l, int r, int pos){
    seg[pos].mn += seg[pos].lz;
    seg[pos].mx += seg[pos].lz;
    if (l != r){
        seg[pos * 2].lz += seg[pos].lz;
        seg[pos * 2 + 1].lz += seg[pos].lz;
    }
    seg[pos].lz = 0;
}
 
void upd(int l, int r, int pos, int ql, int qr, int x){
    if (seg[pos].lz != 0){
        updlz(l, r, pos);
    }
    
    if (l >= ql && r <= qr){
        seg[pos].mn += x;
        seg[pos].mx += x;
        
        if (l != r){
            seg[pos * 2].lz += x;
            seg[pos * 2 + 1].lz += x;
        }
    } else if (l > qr || r < ql){
        return;
    } else {
        int mid = (l + r) / 2;
        
        upd(l, mid, pos * 2, ql, qr, x);
        upd(mid + 1, r, pos * 2 + 1, ql, qr, x);
        
        seg[pos].mn = min(seg[pos * 2].mn, seg[pos * 2 + 1].mn);
        seg[pos].mx = max(seg[pos * 2].mx, seg[pos * 2 + 1].mx);
    }
}
 
void prune(int l, int r, int pos, int x){
    if (seg[pos].lz != 0) updlz(l, r, pos);
    if (seg[pos].mx <= x) return;
    if (l == r){
        seg[pos].mn = INF;
        seg[pos].mx = -INF;
        return;
    }
    
    int mid = (l + r) / 2;
    prune(l, mid, pos * 2, x);
    prune(mid + 1, r, pos * 2 + 1, x);
    
    seg[pos].mn = min(seg[pos * 2].mn, seg[pos * 2 + 1].mn);
    seg[pos].mx = max(seg[pos * 2].mx, seg[pos * 2 + 1].mx);
}
 
int find(int l, int r, int pos){
    if (l == r) return l;
    
    int mid = (l + r) / 2;
    if (seg[pos * 2].mx >= seg[pos * 2 + 1].mx) return find(l, mid, pos * 2);
    else return find(mid + 1, r, pos * 2 + 1);
}
 
void Solve() 
{
    cin >> n;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    cin >> q;
    for (int i = 1; i <= n + 1; i++){
        b[i].clear();
        diff[i] = 0;
    }
    
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i] >> d[i];
        b[l[i]].push_back(i);
        b[r[i] + 1].push_back(-i);
    }
    
    for (int i = 0; i <= 4 * (q + 1); i++){
        seg[i].mn = 0;
        seg[i].mx = 0;
        seg[i].lz = 0;
    }
    
    for (int i = 1; i <= n; i++){
        for (auto x : b[i]){
            if (x > 0){
                // update range [x, q] with +d[x] 
                upd(0, q, 1, x, q, d[x]);
            } else {
                x = -x;
                // update range [x, q] with -d[x]
                upd(0, q, 1, x, q, -d[x]);
            }
        }
        
        int gl_mn = seg[1].mn;
      //  cout << gl_mn << " ";
        prune(0, q, 1, gl_mn);
    }
    
    int id = find(0, q, 1);
    
    for (int i = 1; i <= id; i++){
        diff[l[i]] += d[i];
        diff[r[i] + 1] -= d[i];
    }
    
    for (int i = 1; i <= n; i++){
        diff[i] += diff[i - 1];
        cout << a[i] + diff[i] << " \n"[i == n];
    }
}
 
int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}