// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for(int i=n-2; i>=0; i--){
            while(a[i+1] % a[i] == 0) a[i]++;
        }
        for (auto it : a)
            cout << it << " ";
        cout << endl;
    }
}