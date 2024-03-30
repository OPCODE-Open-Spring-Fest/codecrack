//Write your code here
// Code by Jagpret153
//Approach The longest common substring is calculated using dynamic programming
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int maxLength = 0, endIndex = 0;

    for (int i=1;i<=n;i++) 
    {
        for (int j=i+1;j<=n;j++) 
        {
            if(s[i-1] == s[j-1]) 
            {
                dp[i][j] = dp[i-1][j-1]+1;
                if (dp[i][j]>maxLength) 
                {
                    maxLength=dp[i][j];
                    endIndex=i-1;
                }
            }
        }
    }

    if (maxLength == 0) {
        cout << -1 << endl;
    } else {
        cout << s.substr(endIndex - maxLength + 1, maxLength) << endl;
    }

    return 0;
}