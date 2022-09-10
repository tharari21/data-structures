#include <iostream>

// By default struct members are public and class members are private
int main() {
    struct Rectangle {
        // int is 4 bytes so our rectangle holds 8 bytes
        int width;
        int length;
    };
    // Initialize rectangle with width of 10 and length of 5
    // This is created on the stack
    struct Rectangle r = {10,5};
    // 8 because each int is 4 bytes and we store 2
    std::cout << sizeof(r);
    
    // Array of structs - this array contains 8 bytes * 20 indices = 160 bytes
    // struct Rectangle myRectangles[20];
    // We can initialize some as well with the declaration
    struct Rectangle myRectangles[20] = {{10,20}, {1,2}, {3,5}};
}
