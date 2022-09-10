#include <iostream>

/*
Each function gets it's own stack frame
*/
int main() {
    // Each character is one byte

    // Strings are an array of chars
    // char name[6] = {'t','o','m','e','r', '\0'};
    // The \0 tells the char array when it ends
    // char name[] = {'t','o','m','e','r', '\0'};
    // String literals are constants. They automatically get a null termination character attached 
    char name[] = "tomer";
    // Just like with arrays, char arrays cannot be reassigned
    // Neither of these 2 statements work
    // name = "something else";
    // name[] = "something else";
    int arr[] = {1,2,3,4};
    // Just like this would not work
    // arr[] = {4,3,2,1};
    // arr = {4,3,2,1};
    std::cout << name << std::endl;
    std::cout << sizeof(name);
}