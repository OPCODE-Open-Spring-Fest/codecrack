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
        int arr[n];
        int count = 0;
        for (int i = 0 ; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 2)
            {
                count++;
            }
        }
        if (n == 1)
        {
            cout << -1 << endl;
            continue;
            ;
        }
        if (count % 2 == 1)
        {
            cout << -1 << endl;
            continue;
        }

        else
        {
            int count2 = 0;
            int i = 0;
            while (count2 <(count / 2))
            {
                if (arr[i] == 2)
                {
                    count2++;
                }
                i++;
            }
            if (i == 0)
                i++;

            cout << i << endl;
        }
    }
}