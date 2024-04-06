// write your code here
#include <bits/stdc++.h>
#include <iostream>
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
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 2)
            {
                count++;
            }
        }
        if (n == 1)
        {
            cout << -1 << endl;
            exit(0);
        }
        if (count % 2 == 1)
        {
            cout << -1 << endl;
            exit(0);
        }

        else
        {
            int count2=0;
            int i=0;
            while(count2<count/2)
            {
                if(a[i]==2)
                {
                    count2++;
                }
                i++;
            }
            if(i==0)i++;
            cout<<i<<endl;
        }

    }
}