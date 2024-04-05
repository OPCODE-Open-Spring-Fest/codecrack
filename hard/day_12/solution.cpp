//write your code here
// Code by Jagpreet153 
#include <bits/stdc++.h>
using namespace std;
// Approach is to precompute the cost to make the string beautiful up to each position for each permutation
int main() 
{
    int n, q;
    cin>>n>>q;
    string s;
    cin >> s;
    vector<string> all{"abc", "acb", "bac", "bca", "cab", "cba"};

    // Initialize a 2D array to store the cost to make the string beautiful up to each position for each permutation
    vector<vector<int>> cost(7, vector<int>(n+1));

    // For each permutation
    for(int x = 0; x < 6; x++) 
    {
        int index = 0;
        // For each position in the string
        for(int i = 1; i <= n; i++) 
        {
            // Carry over the cost from the previous position
            cost[x][i] = cost[x][i-1];
            // If the character at the current position does not match the corresponding character in the permutation, increment the cost
            if(s[i-1] != all[x][index]) 
            {
                cost[x][i]++;
            }
            // Move to the next character in the permutation, wrapping around to the start if necessary
            index++;
            if(index ==3) 
            index = 0;
        }
    }

    // For each query
    while(q--) 
    {
        // Read the start and end of the query range
        int a, b;
        cin>>a>>b;

        // Initialize the minimum cost to the maximum possible integer
        int ans =INT_MAX;

        // For each permutation, calculate the cost for the substring and update the minimum cost if necessary
        for(int x=0;x<6;x++) {
            ans = min(ans, cost[x][b] - cost[x][a-1]);
        }

        // Print the minimum cost
        cout << ans << "\n";
    }
}
