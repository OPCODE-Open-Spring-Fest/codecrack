#include <iostream>
using namespace std;

void mysteryFunction() {
    int* ptr = new int;  //Allocate memory for the pointer
    *ptr = 10; 
    cout << *ptr << endl;
    delete ptr;  //Deallocate memory to avoid memory leaks
}
int main() {
    mysteryFunction();
    return 0;
}

// In the original code, the program tried to use a pointer without giving it a proper place to point to, leading to garbage output. I fixed it by allocating memory for the pointer using "new int" before using it and then deallocating the memory using "delete" when done to avoid memory leaks.

