// Write your solution here
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void function1() {
    int n;
    cin >> n;
    int p[n], q[n], maxFreq[n*2];
    for (int i = 1; i <= n * 2; i++)
        maxFreq[i] = 0;
    int count = 0; 
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] != p[i - 1])
            count = 1; 
        else
            count++; 
        maxFreq[p[i]] = max(maxFreq[p[i]], count); 
        ans = max(ans, count); 
    }
    count = 0; 
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
        if (q[i] != q[i - 1])
            count = 1; 
        else
            count++; 
        ans = max(ans, count + maxFreq[q[i]]); 
    }
    cout << ans << "\n";
}
int main() {
    int t;
    cin >> t;
    while (t--)
        function1();
    return 0;
    
}





