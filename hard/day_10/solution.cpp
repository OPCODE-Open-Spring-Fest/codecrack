// write your code here
#include <bits/stdc++.h>
using namespace std;

// Constant modulus value used for modular arithmetic
const long long MOD = 1000000007;

// Function to calculate modular exponentiation (a^b mod MOD)
long long modpow(long long a, long long b)
{
    long long ans = 1;
    // Loop until b is 0
    while (b > 0)
    {
        // If b is odd, multiply a to the answer and perform modulo operation
        if (b % 2 == 1)
        {
            ans *= a;
            ans %= MOD;
        }
        // Square a and perform modulo operation
        a *= a;
        a %= MOD;
        // Divide b by 2 (for efficient exponentiation)
        b /= 2;
    }
    return ans;
}

// Function to calculate modular inverse (a^-1 mod MOD)
long long modinv(long long a)
{
    // Use modpow to calculate a^(MOD-2)
    return modpow(a, MOD - 2);
}

// Pre-computed factorials (mod MOD) and inverses
vector<long long> mf = {1};
vector<long long> mfi = {1};

// Function to calculate modular factorial (n! mod MOD)
long long modfact(int n)
{
    // If n is already pre-computed, return it
    if (mf.size() > n)
    {
        return mf[n];
    }
    else
    {
        // Iterate from the end of the pre-computed values to n
        for (int i = mf.size(); i <= n; i++)
        {
            // Calculate next factorial and its inverse (mod MOD)
            long long next = mf.back() * i % MOD;
            mf.push_back(next);
            mfi.push_back(modinv(next));
        }
        return mf[n];
    }
}

int main()
{
    // Input n (number of elements) and k (group size)
    int n, k;
    cin >> n >> k;

    // Pre-compute inverses for 1 to k+1 (mod MOD)
    vector<long long> INV(k + 2);
    for (int i = 1; i < k + 2; i++)
    {
        INV[i] = modinv(i);
    }

    // Pre-compute binomial coefficients (mod MOD) using pre-calculated factorials and inverses
    vector<vector<long long>> binom(k * 2 + 1, vector<long long>(k + 2, 0));
    for (int i = 0; i <= k * 2; i++)
    {
        for (int j = 0; j <= k + 1; j++)
        {
            int a = n - i, b = j;
            // Check for valid range of a and b for calculating binomial coefficient
            if (a >= 0 && 0 <= b && b <= a)
            {
                binom[i][j] = 1;
                for (int x = 0; x < b; x++)
                {
                    // Calculate binomial coefficient using formula with modular arithmetic
                    binom[i][j] *= a - x;
                    binom[i][j] %= MOD;
                    binom[i][j] *= INV[x + 1];
                    binom[i][j] %= MOD;
                }
            }
        }
    }

    // dp table to store intermediate results
    vector<vector<long long>> dp(k + 1, vector<long long>(k + 1, 0));
    // Base case: dp[0][0] = 1 (empty group)
    dp[0][0] = 1;

    // Dynamic programming loop to fill the dp table
    for (int i = 1; i <= k; i++)
    {
        for (int j = k - i; j >= 0; j--)
        {
            for (int c = 0; c < k; c++)
            {
                // If there are elements in the current group (dp[j][c] > 0)
                if (dp[j][c] > 0)
                {
                    long long p = 1;
                    int c2 = j + c;
                    int cnt = 0;
                    for (int j2 = j + i; j2 <= k; j2 += i)
                    {
                        c2 += i + 1;
                        if (c2 > n)
                        {
                            break;
                        }
                        cnt++;
                        if (c + cnt > k)
                        {
                            break;
                        }
                        p *= binom[c2 - (i + 1)][i + 1];
                        p %= MOD;
                        p *= modfact(i);
                        p %= MOD;
                        p *= INV[cnt];
                        p %= MOD;
                        dp[j2][c + cnt] += dp[j][c] * p;
                        dp[j2][c + cnt] %= MOD;
                    }
                }
            }
        }
    }
    vector<long long> ans(k + 1, 0);
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            ans[i] += dp[i][j];
            ans[i] %= MOD;
        }
    }
    for (int i = 0; i < k - 1; i++)
    {
        ans[i + 2] += ans[i];
        ans[i + 2] %= MOD;
    }
    for (int i = 1; i <= k; i++)
    {
        cout << ans[i];
        if (i < k)
        {
            cout << ' ';
        }
    }
    cout << endl;
}