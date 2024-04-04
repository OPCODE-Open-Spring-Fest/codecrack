//write your code here
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(int x) {
    string s = to_string(x);
    int cnt = 0;
    for (char c : s) {
        if (c != '0') {
            cnt++;
        }
    }
    return cnt == 1;
}

int main() {
    vector<int> a;
    for (int i = 1; i < 1000000; ++i) {
        if (check(i)) {
            a.push_back(i);
        }
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int ans = 0;
        for (int x : a) {
            if (x <= n) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
