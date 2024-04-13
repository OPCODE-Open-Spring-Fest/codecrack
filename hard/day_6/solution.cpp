#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;i++) // Macro for looping from a to b

char leftString[1010], rightString[1010]; // Arrays for storing left and right strings
int stateCount, transitions[20000][10], suffixLinks[20000], prefixSums[17000][2010], length, n, dp[2005][17000], reachable[2005][17000], leftLength, rightLength; // Variables for counting, storing transitions, and dynamic programming

int newState(int x, int y){
    return !transitions[x][y] ? transitions[x][y] = ++stateCount : transitions[x][y]; // Function to get or create a new state
}

void insertStrings(){
    leftLength = strlen(leftString + 1), rightLength = strlen(rightString + 1); // Get the lengths of left and right strings
    int x = 0, y = 0; // Initialize states for left and right strings
    if(leftLength == rightLength){ // If lengths are equal
        fo(i, 1, leftLength){
            if(x == y){
                fo(j, leftString[i] - '0' + 1, rightString[i] - '0' - 1)
                    prefixSums[newState(x, j)][leftLength - i]++; // Increment count for transitions
                x = newState(x, leftString[i] - '0'); // Transition to next state
                y = newState(y, rightString[i] - '0'); // Transition to next state
            }
            else{
                fo(j, leftString[i] - '0' + 1, 9)
                    prefixSums[newState(x, j)][leftLength - i]++; // Increment count for transitions
                x = newState(x, leftString[i] - '0'); // Transition to next state
                fo(j, (i == 1), rightString[i] - '0' - 1)
                    prefixSums[newState(y, j)][rightLength - i]++; // Increment count for transitions
                y = newState(y, rightString[i] - '0'); // Transition to next state
            }
        }
        prefixSums[x][0]++; // Increment count for final state
        if(x != y) prefixSums[y][0]++; // Increment count for final state
    }
    else{
        fo(i, 1, leftLength){
            fo(j, leftString[i] - '0' + 1, 9)
                prefixSums[newState(x, j)][leftLength - i]++; // Increment count for transitions
            x = newState(x, leftString[i] - '0'); // Transition to next state
        }
        fo(i, 1, rightLength){
            fo(j, (i == 1), rightString[i] - '0' - 1)
                prefixSums[newState(y, j)][rightLength - i]++; // Increment count for transitions
            y = newState(y, rightString[i] - '0'); // Transition to next state
        }
        fo(i, leftLength + 1, rightLength - 1)
            fo(j, 1, 9)
                prefixSums[newState(0, j)][i - 1]++; // Increment count for transitions
        prefixSums[x][0]++; // Increment count for final state
        prefixSums[y][0]++; // Increment count for final state
    }
}

queue<int> bfsQueue; // Queue for BFS

void buildAutomaton(){
    fo(i, 0, 9) if(transitions[0][i])
        bfsQueue.push(transitions[0][i]); // Push initial states to the queue
    while(!bfsQueue.empty()){
        int currentState = bfsQueue.front();
        bfsQueue.pop();
        fo(i, 0, rightLength - 1)
            prefixSums[currentState][i] += prefixSums[suffixLinks[currentState]][i]; // Update counts using suffix link
        fo(i, 0, 9){
            if(transitions[currentState][i]){
                bfsQueue.push(transitions[currentState][i]);
                suffixLinks[transitions[currentState][i]] = transitions[suffixLinks[currentState]][i]; // Set suffix link
            }
            else transitions[currentState][i] = transitions[suffixLinks[currentState]][i]; // Set transition
        }
    }
    fo(i, 0, stateCount)
        fo(j, 1, n)
            prefixSums[i][j] += prefixSums[i][j - 1]; // Compute prefix sums
}

int main(){
    scanf("%s%s%d", leftString + 1, rightString + 1, &n); // Input left, right strings, and n
    insertStrings(); // Construct automaton
    buildAutomaton(); // Build automaton
    memset(dp, -32, sizeof(dp)); // Initialize DP table
    dp[0][0] = 0; // Base case
    fo(i, 0, n - 1)
        fo(j, 0, stateCount)
            if(dp[i][j] >= 0)
                fo(k, 0, 9)
                    dp[i + 1][transitions[j][k]] = max(dp[i + 1][transitions[j][k]], dp[i][j] + prefixSums[transitions[j][k]][n - i - 1]); // DP transition
    int result = -1e9; // Initialize result
    fo(i, 0, stateCount)
        result = max(result, dp[n][i]); // Update result
    printf("%d\n", result); // Output result

    fo(i, 0, stateCount)
        reachable[n][i] = (result == dp[n][i]); // Mark states achieving the result
    for(int i = n - 1; i; i--)
        fo(j, 0, stateCount)
            fo(k, 0, 9)
                reachable[i][j] |= reachable[i + 1][transitions[j][k]] && (dp[i + 1][transitions[j][k]] == dp[i][j] + prefixSums[transitions[j][k]][n - i - 1]); // Mark states for next iteration
    int currentState = 0; // Initialize state
    fo(i, 1, n)
        fo(k, 0, 9)
            if(reachable[i][transitions[currentState][k]] && dp[i][transitions[currentState][k]] == dp[i - 1][currentState] + prefixSums[transitions[currentState][k]][n - i]){
                printf("%d", k); // Output character
                currentState = transitions[currentState][k]; // Transition to next state
                break;
            }
}