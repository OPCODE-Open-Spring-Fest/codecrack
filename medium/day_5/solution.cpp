// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int n, sum = 0;
    cin >> n;
    vector<int> a(n), ans;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        vp.push_back({a[i], i});
    }
    if (n <= 2)
    {
        cout << 0 << endl;
    }
    else
    {
        sort(vp.begin(), vp.end());
        for (int i = 0; i < n; i++)
        {
            if (i != n - 1)
            {
                int k = sum - vp[i].first;
                if (2 * vp[n - 1].first == k)
                    ans.push_back(vp[i].second + 1);
            }
            else
            {
                int k = sum - vp[i].first;
                if (2 * vp[n - 2].first == k)
                    ans.push_back(vp[i].second + 1);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
}