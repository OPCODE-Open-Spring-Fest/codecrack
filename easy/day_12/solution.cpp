//write your code here
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int findMinDigitsToRemove(int num) {
    vector<char> numString;
    while (num != 0) {
        int remainder = num % 10;
        char digit = (remainder + '0');
        numString.push_back(digit);
        num /= 10;
    }

    reverse(numString.begin(), numString.end());

    int minRemovals = INT_MAX;
    int size = numString.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int formedNumber = (numString[i] - '0') * 10 + (numString[j] - '0');

            if (formedNumber % 25 == 0) {
                int countBefore = j - i - 1;
                int countAfter = size - (j + 1);
                minRemovals = min(minRemovals, countBefore + countAfter);
            }
        }
    }

    return minRemovals;
}

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int testNumber;
        cin >> testNumber;
        int minRemovals = findMinDigitsToRemove(testNumber);
        if (minRemovals == INT_MAX) {
            cout << -1 << endl;
        }
        else {
            cout << minRemovals << endl;
        }
    }
    return 0;
}
