// Copde by Jagpreet 153
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        cin >> s;
        vector<int> cnt(26);
        for(auto &c: s) cnt[c - 'a']++;
        vector<int> _cnt = cnt;
        sort(cnt.rbegin(), cnt.rend());
        int ans = n;
        int tmp = -1;
        for (int i = 1; i <= 26; ++i) {
            if (n % i) continue;
            int cur = 0;
            for (int j = 0; j < i; ++j) {
                cur += min(cnt[j], n / i);
            }
            if (n - cur < ans){
                ans = n - cur;
                tmp = i;
            }
            ans = min(ans, n - cur);
        }
        vector<int> take(26);
        vector<pair<int, char>> temp;
        for (int i = 0; i < 26; ++i) {
            temp.emplace_back(_cnt[i], 'a' + i);
        }
        sort(temp.rbegin(), temp.rend());
        for (int i = 0; i < tmp; ++i) {
            take[temp[i].second - 'a'] = 1;
        }
        tmp = n / tmp;
        vector<int> cur_cnt(26);
        vector<int> good(n);
        for (int i = 0; i < n; ++i) {
            int c = s[i]  - 'a';
            if (!take[c]) continue;
            if (cur_cnt[c] < tmp){
                cur_cnt[c]++;
                good[i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if (!good[i]){
                for (int j = 0; j < 26; ++j) {
                    if (take[j] && cur_cnt[j] < tmp){
                        s[i] = 'a' + j;
                        cur_cnt[j]++;
                        break;
                    }
                }
            }
        }
        cout << ans << '\n';
        cout << s << '\n';
    }
    return 0;
}