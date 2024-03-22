#include <iostream>

/* Earlier ptr was only declared not initialized. This means it doesn't point to a valid memory location. It contains a garbage value, pointing to some arbitrary location in memory.

We need to ensure that the pointer ptr points to a valid memory location (maybe a variable like value) before dereferencing it.  */

void mysteryFunction() {
    int value;
    int* ptr=&value;
    *ptr = 10; 
    std::cout << *ptr << std::endl;
}

int main() {
    mysteryFunction();
    return 0;
}
