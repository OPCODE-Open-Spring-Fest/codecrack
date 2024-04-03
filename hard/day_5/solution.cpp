
#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
struct S{
  pair<long long, int> mn1, mn2;
  S(long long x = INF, int idx = -1): mn1({x, idx}), mn2({INF, idx}){
  }
};
S op(S a, S b){
  S ans;
  ans.mn1 = min(a.mn1, b.mn1);
  if (a.mn1.first < b.mn1.first){
    ans.mn2 = min(a.mn2, b.mn1);
  } else if (a.mn1.first > b.mn1.first){
    ans.mn2 = min(a.mn1, b.mn2);
  } else {
    ans.mn2 = min(a.mn2, b.mn2);
  }
  return ans;
}
S mp(long long x, S a){
  a.mn1.first += x;
  a.mn2.first += x;
  return a;
}
struct lazy_segment_tree{
  int N;
  vector<S> ST;
  vector<long long> lazy;
  lazy_segment_tree(vector<S> &A){
    int n = A.size();
    N = 1;
    while (N < n){
      N *= 2;
    }
    ST = vector<S>(N * 2 - 1);
    for (int i = 0; i < n; i++){
      ST[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
    lazy = vector<long long>(N * 2 - 1, 0);
  }
  void push(int i){
    if (i < N - 1){
      lazy[i * 2 + 1] += lazy[i];
      lazy[i * 2 + 2] += lazy[i];
    }
    ST[i] = mp(lazy[i], ST[i]);
    lazy[i] = 0;
  }
  void range_apply(int L, int R, long long x, int i, int l, int r){
    push(i);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      lazy[i] = x;
      push(i);
    } else {
      int m = (l + r) / 2;
      range_apply(L, R, x, i * 2 + 1, l, m);
      range_apply(L, R, x, i * 2 + 2, m, r);
      ST[i] = op(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void range_apply(int L, int R, long long x){
    range_apply(L, R, x, 0, 0, N);
  }
  S all(){
    push(0);
    return ST[0];
  }
};
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int q;
    cin >> q;
    vector<int> l(q), r(q), x(q);
    for (int j = 0; j < q; j++){
      cin >> l[j] >> r[j] >> x[j];
      l[j]--;
    }
    vector<vector<int>> L(n + 1), R(n + 1);
    for (int j = 0; j < q; j++){
      L[l[j]].push_back(j);
      R[r[j]].push_back(j);
    }
    vector<S> A(q + 1);
    for (int j = 0; j <= q; j++){
      A[j] = S(0, j);
    }
    lazy_segment_tree ST(A);
    vector<long long> ans(n);
    for (int j = 0; j < n; j++){
      ST.range_apply(0, q + 1, a[j]);
      for (int t : L[j]){
        ST.range_apply(t + 1, q + 1, x[t]);
      }
      for (int t : R[j]){
        ST.range_apply(t + 1, q + 1, -x[t]);
      }
      ans[j] = ST.all().mn1.first;
      while (true){
        S res = ST.all();
        if (res.mn2.first >= INF / 2){
          break;
        }
        int idx = res.mn2.second;
        ST.range_apply(idx, idx + 1, INF);
      }
      ST.range_apply(0, q + 1, -a[j]);
    }
    for (int j = 0; j < n; j++){
      cout << ans[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}