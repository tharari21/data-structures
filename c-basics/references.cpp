#include <iostream>
/*
References are simply an alias.
*/
int main() {
    int a = 10;
    // r is referencing a. r is now an alias of a
    int &r = a;

    r++; // increments a and r
    a++; // increments a and r

    // Address of a and r are equal
    std::cout << "address of r" << &r << std::endl;
    std::cout << "address of a: " << &a << std::endl;
    // Why do we need references if it's just an alias?
    // Useful in parameter passing - instead of passing by value we pass by reference
    // and we have access to the parameter passed in in the function

    // references must be initialized
    // int &r1;

    int b=25;
    // Don't be fooled, this statement will also make a 25 as well as r and b
    r = b;
    // References don't take up memory it's just another way to reference the variable

   

}