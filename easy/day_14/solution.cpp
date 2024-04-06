// write your code here
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n == 1)
        {
            cout << -1 << endl;
            exit(0);
        }
        int mini = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            long long productK = 1, productRem = 1;
            for (int i = 0; i <= k; i++)
            {
                productK *= a[i];
            }
            for (int i = k + 1; i < n; i++)
            {
                productRem *= a[i];
            }
            if (productK == productRem)
            {
                if (k + 1 < mini)
                    mini = k + 1;
            }
        }
        if (mini == INT_MAX)
            cout << -1 << endl;
        else
            cout << mini << endl;
    }
}