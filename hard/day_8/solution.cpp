//write your code here
#include <bits/stdc++.h>
using namespace std;

// Function to read an integer from standard input
inline int in() { int x; scanf("%d", &x); return x; }

// Constant for array size
const int N = 505;

int main()
{
    int n, k;
    // Reading the values of n and k from standard input
    cin >> n >> k;

    // Dynamic programming array to store state information
    bool dp[2][N][N];
    // Initializing the first state
    dp[0][0][0] = 1;

    // Iterating over each integer from 1 to n
    for(int i = 1; i <= n; i++)
    {
        // Determining the current and last states
        int now = i % 2;
        int last = 1 - now;
        // Reading the value x for the current integer
        int x = in();

        // Looping over possible sums j and counts y
        for(int j = 0; j <= k; j++)
            for(int y = 0; y <= j; y++)
            {
                // Updating the dp array based on the previous state and current value of x
                dp[now][j][y] = dp[last][j][y];
                if(j >= x)
                {
                    dp[now][j][y] |= dp[last][j - x][y];
                    if(y >= x)
                        dp[now][j][y] |= dp[last][j - x][y - x];
                }
            }
    }

    // Vector to store the results
    vector <int> res;
    // Finding all possible values of y such that dp[n % 2][k][y] is true
    for(int i = 0; i <= k; i++)
        if(dp[n % 2][k][i])
            res.push_back(i);

    // Outputting the number of possible sums and the values in res
    cout << res.size() << endl;
    for(int x : res)
        cout << x << " ";
    cout << endl;
}
