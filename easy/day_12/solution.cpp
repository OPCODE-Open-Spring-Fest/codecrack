#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        if (n % 25 == 0)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            int count = 0;
            bool p = true;
            while (p)
            {
                long long int s = ((n - (n % 10)) / 10) % 10;
                if ((n % 10 == 0 && (s == 0 || s == 5)) || (n % 10 == 5 && (s == 2 || s == 7)))
                {
                    cout << count << endl;
                    p = false;
                }
                else if ((n % 10 != 5) && (n % 10 != 0))
                {
                    n = n / 10;
                    count++;
                }
                else if ((n % 10 == 0 && (s != 0 && s != 5)))
                {
                    n = ((n - n % 100) + ((n % 10) * 10)) / 10;
                    count++;
                }

                else if ((n % 10 == 5 && (s != 2 && s != 7 && s != 0)))
                {

                    n = ((n - n % 100) + ((n % 10) * 10)) / 10;
                    count++;
                }
                else if ((n % 10 == 5) && (s == 0))
                {

                    long long int tl = (n % 1000) / 100;
                    if (tl == 0 || tl == 5)
                    {
                        n = n / 10;
                        count++;
                    }
                    else if (tl == 2 || tl == 7)
                    {
                        n = ((n - n % 100) + ((n % 10) * 10)) / 10;
                        count++;
                    }
                    else
                    {
                        n = (n - (n % 1000) + (((n % 1000) % 100) * 10)) / 10;
                        count++;
                    }
                }
            }
        }
    }

    return 0;
}
