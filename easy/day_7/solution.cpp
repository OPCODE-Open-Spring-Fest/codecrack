#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int d;
        cin >> d;
        if (d == 1)
        {
            cout << 6 << endl;
            continue;
        }

        long long int fac1 = 1 + d;
        bool p = true;
        while (p)
        {
            for (int i = 2; i < fac1; i++)
            {
                if ((fac1 % i) == 0)
                {
                    fac1++;
                    break;
                }
                if (i == fac1 - 1)
                {
                    p = false;
                }
            }
        }
        bool q = true;
        long long int fac2 = fac1 + d;
        while (q)
        {
            for (int i = 2; i < fac2; i++)
            {
                if ((fac2 % i) == 0)
                {
                    fac2++;
                    break;
                }
                if (i == fac2 - 1)
                {
                    q = false;
                }
            }
        }

        cout << fac1 * fac2 << endl;
    }
    return 0 ;
}
