//write your code here
//Code by Jagpreet153
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXK = 200;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n+1, vector<int>(MAXK+1));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= min(i*(i-1)/2, k); j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= i) {
                dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD) % MOD;
            }
        }
    }

    int total = 0;
    for(int j = 0; j <= k; j++) {
        total = (total + dp[n][j]) % MOD;
        cout << total << " ";
    }

    return 0;
}