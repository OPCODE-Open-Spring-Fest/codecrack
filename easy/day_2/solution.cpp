#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    if(n<0) {
        n*=-1;
    }
    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        sum+=num;
    }
    cout << "Sum of the " << n << " numbers is: " << sum << endl;
    return 0;
}
