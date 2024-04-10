#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a > b)
        {
            cout << "First" << endl;
        }
        else if (b > a)
        {
            cout << "Second" << endl;
        }
        else
        {
            if (c % 2 == 0)
            {
                cout << "Second" << endl;
            }
            else
            {
                cout << "First" << endl;
            }
        }
    }
}