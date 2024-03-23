#include<iostream>

int main()
{
    int n;
    int sum = 0;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    n = (n<0)?(-1*n):n;
     std::cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i)
    {
        int num;
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> num;
        sum += num;
    }
    std::cout << "Sum of the " << n << " numbers is: " << sum << std::endl;
    return 0;
}
