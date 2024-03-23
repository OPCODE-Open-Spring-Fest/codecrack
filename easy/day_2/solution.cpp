#include <iostream>

int main() {
    int n;
    long long sum = 0;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    if(n<0) n *= -1;
    std::cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i) {
        long long num;
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> num;
        sum += num;
    }
    std::cout << "Sum of the " << n << " numbers is: " << sum << std::endl;
    return 0;
}
