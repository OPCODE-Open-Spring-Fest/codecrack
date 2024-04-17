//write your code here
//Code by Jagpreet153
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long res = 1;
    string b;
    cin >> b;
    vector<bool> z(10, true);
    int num0 = 0;
    int num = 0;
    if (b[0] == '?') 
    res = 9;
    else if (b[0] - 'A' < 10 && b[0] - 'A' >= 0) 
    {
        res = 9;
        z[b[0] - 'A'] = false;
        num++;
    }
    for (int i = 1; i < b.size(); i++) 
    {
        if (b[i] == '?')
         num0++;
         else if (b[i] - 'A' < 10 && b[i] - 'A' >= 0) 
         {
            if (z[b[i] - 'A']) 
            {
                res *= 10 - num;
                num++;
                z[b[i] - 'A'] = false;
            }
        }
    }
    cout << res;
    for (int i = 0; i < num0; i++) {
        cout << "0";
    }

    return 0;
}