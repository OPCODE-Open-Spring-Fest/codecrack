#include <iostream>

void mysteryFunction() {
    int* ptr;
    *ptr = 10; 
    std::cout << *ptr << std::endl;
}

int main() {
    mysteryFunction();
    return 0;
}
