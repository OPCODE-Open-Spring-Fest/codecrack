#include <bits/stdc++.h> // Include necessary header files
using namespace std;
typedef long long ll; // Define a shorthand for long long

const int MAXN = 5e5 + 5; // Define maximum array size

ll initialArray[MAXN], differences[MAXN]; // Declare arrays for storing initial values and differences
map<int, ll> valueChanges; // Declare a map to store the changes in values
int queryLeft[MAXN], queryRight[MAXN]; ll queryValue[MAXN]; // Arrays to store left, right, and value changes for queries

int main() { 
    ios::sync_with_stdio(0); cin.tie(0); // Fast I/O

    int t; cin >> t; // Input number of test cases
    while (t--) { // Iterate over each test case
        int n; cin >> n; // Input array size
        for (int i = 1; i <= n; i++) // Input the initial array
            cin >> initialArray[i];
        int ans = 0; // Initialize the answer variable

        int q; cin >> q; // Input number of queries
        for (int i = 1; i <= q; i++) { // Loop over each query
            int left, right; ll value; cin >> left >> right >> value; // Input query parameters
            queryLeft[i] = left; queryRight[i] = right, queryValue[i] = value; // Store query parameters
            valueChanges[left] += value; // Update the map with the value change
            if (right + 1 <= n)
                valueChanges[right + 1] -= value; // Adjust for the end of the range
            while (!valueChanges.empty() && valueChanges.begin()->second == 0) // Remove zero values from the map
                valueChanges.erase(valueChanges.begin());
            if (!valueChanges.empty() && valueChanges.begin()->second < 0) { // If there's a negative value in the map
                ans = i; // Update the answer with the current query index
                valueChanges.clear(); // Clear the map
            }
        }

        for (int i = 1; i <= ans; i++) { // Process queries up to the answer
            int left = queryLeft[i], right = queryRight[i]; ll value = queryValue[i]; // Retrieve query parameters
            differences[left] += value; // Update difference array at start index
            if (right + 1 <= n)
                differences[right + 1] -= value; // Adjust difference array at end index
        }

        for (int i = 1; i <= n; i++) { // Apply differences to the array
            differences[i] += differences[i - 1]; // Accumulate differences
            initialArray[i] += differences[i]; // Update array value
            cout << initialArray[i] << " \n"[i == n]; // Output array value
        }

        // Initialize arrays and map for the next test case
        for (int i = 1; i <= n; i++)
            differences[i] = 0;
        valueChanges.clear();
    }
    return 0; // End of program
}