#include <bits/stdc++.h>
#define lil long long int
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lil n;
        cin >> n;
        lil a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        lil c = 1, s = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
                c++;
            else
            {
                if (c >= 3)
                    s += c * (c - 1) * (c - 2) / 6;
                if (i - c > 0)
                    s += c * (c - 1) / 2 * (i - c);
                c = 1;
            }
        }
        if (c >= 3)
            s += c * (c - 1) * (c - 2) / 6;
        if (n - c > 0)
            s += c * (c - 1) / 2 * (n - c);
        cout << s << endl;
    }
}
