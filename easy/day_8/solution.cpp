//write your code here
#include <iostream>
using namespace std;
typedef long long int ll;

int main() {
    ll a;
    cin >> a;
    while (a--) {
        ll x, y, k;
        cin >> x >> y >> k;
        ll p = (y * k) + k;

        ll total_steps;
        if (x == 1) {
            total_steps = p + k;
        } else if (((p - 1) % (x - 1)) == 0) {
            total_steps = ((p - 1) / (x - 1)) + k;
        } else {
            total_steps = ((p - 1) / (x - 1)) + 1 + k;
        }

        cout << total_steps << endl;
    }
    return 0;
}
