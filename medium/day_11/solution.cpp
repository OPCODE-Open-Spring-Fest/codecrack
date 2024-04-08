//write your code here
// Code by Jagpreet153
#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;
    while(q--) {
        long long int k;
        cin >> k;
        long long int len = 1, cnt = 9, start = 1;
        while(k > len * cnt) {
            k -= len * cnt;
            len++;
            cnt *= 10;
            start *= 10;
        }
        start += (k - 1) / len;
        string s = to_string(start);
        cout << s[(k - 1) % len] << endl;
    }
    return 0;
