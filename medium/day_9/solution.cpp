//write your code here
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    // Read input values A, B, and N
    int A, B, N;
    scanf("%d%d%d", &A, &B, &N);

    // Store the original value of A
    int original_A = A;

    // Array to store the digits of the answer
    static int answer_digits[100000];

    // Iterate through each digit of the answer
    for (int i = 0; i < N; i++) {
        answer_digits[i] = -1;
        
        // Try all possible digits (0 to 9) to append to A
        for (int j = 0; j < 10; j++) {
            // Check if appending j to A results in a number divisible by B
            if (!((A * 10 + j) % B)) {
                // Store the digit j in the answer
                answer_digits[i] = j;
            }
        }

        // If no digit is found to append, print -1 and exit
        if (answer_digits[i] == -1) {
            printf("-1\n");
            return 0;
        }

        // Update A for the next iteration
        A = 0;
    }

    // Print the original value of A
    printf("%d", original_A);

    // Print the digits of the answer
    for (int i = 0; i < N; i++)
        putchar(answer_digits[i] + 48);
    putchar('\n');

    return 0;
}
