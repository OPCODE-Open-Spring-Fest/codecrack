//write your code here
#include <bits/stdc++.h>
using namespace std;

int leastk(int n, vector<int> &sequence)
{
    int c = 1, p = 1;

    for (int k = 0; k < sequence.size(); ++k)
    {
        int num = sequence[k];
        p = p * num;
    }

    for (int j = 0; j < n; ++j)
    {
        c = c * sequence[j];
        p = p / sequence[j];

        if (c == p)
        {
            return j + 1;
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> sequence(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> sequence[i];
        }
        int ans = leastk(n, sequence);
        cout << ans << endl;
    }

    return 0;
}