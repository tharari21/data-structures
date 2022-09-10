#include <iostream>
#include <stdlib.h>
/*
3 sections of memory - code section on the bottom, heap in the middle, stack on top.
A pointer stores address of data, not the data itself
Why do we need pointers?
Our program can directly access the stack. Heap memory is external to the program
So how do we access memory on the heap? We use pointers. So our program can have pointers to memory on the heap
If we have a file on disk, we cannot access the file directly since it is external, therefore we'd need pointers
Same goes for keyboards, moniters, wifi... any resource outside of program.
Pointers also used for parameter passing
*/
int main() {
    // data variable
    // a is taking up 4 bytes so let's say data address 200-204
    int a = 10;
    // address variable or pointer
    // p is on our main stack frame
    // p is a pointer to an int and also takes 4 bytes
    // let's say p is at address 400-404 - the value stores here is the value 200, the starting point of memory address of a
    int *p;
    p = &a;
    // prints memory location of a
    std::cout << "memory address stored in p: " <<  p << std::endl;
    std::cout << "memory address of a: " <<  &a << std::endl;
    // dereference p and get value
    std::cout << "value at dereferenced p: " << *p << std::endl;

    // Pointing to arrays
    int A[] = {1,2,3,4,5};
    int *pointer;
    // When pointing to an array, we don't need & since what is stored in an array variable is the memory address of the first element.
    pointer = A;
    // if you really wanted to use an & you can do this (it's the same as A)
    // pointer = &A[0];

    // To access the elements in the array using the pointer
    for (int i = 0; i < 5; i++) {
        // std::cout << A[i] << std::endl;
        // We can use the pointer just like we use the variable. This is because A is already a pointer and we assigned pointer to A
        // So pointer is just like A
        std::cout << pointer[i] << std::endl;
    }

    // Note in these examples we were not accessing heap memory. This was just a simple example. Both p and a are on stack

    // Let's access heap data
    // p2 is on stack
    int *p2;

    // to get memory on heap, use malloc(). to use malloc #include <stdlib.h>
    // What we want on our heap is an array of 5 integers. This means we need 5*4 bytes of data. 
    // Instead of manually typing number of bytes of int just use sizeof 
    // malloc returns a void pointer so we need to cast this to an int pointer
    p2 = (int *)malloc(5*sizeof(int));
    p2[0]=2; p2[1]=4; p2[2]=6; p2[3]=8; p2[4]=10;
    for (int i = 0; i < 5; i++) {
        std::cout << p2[i] << std::endl;
    }
    // Now p2 is on stack and points to memory on the heap
    // malloc is a c thing, in c++ we can simply use new keyword to get heap data
    int *p3 = new int[5];
    p3[0] =5;

    // After using malloc or new and getting memory from heap, we need to release it by calling delete
    // for small programs this is not absolutely necessary but it's good to get into habit
    delete [] p3; // the brackets tell c++ we are deleting an array so go until the end of it
    // free(p3); // c lang. use delete in c++

    struct Rectangle {
        int length;
        int width;
    };

    int *pt1;
    double *pt2;
    float *pt3;
    char *pt4;
    struct Rectangle *pt5;

    // All pointers are 8 bytes! because it's only storing an address. They used to be 4 bytes but with modern compilers, it's 8
    std::cout << "Size of int pointer: " << sizeof(pt1) << std::endl;
    std::cout << "Size of double pointer: " << sizeof(pt2) << std::endl;
    std::cout << "Size of float pointer: " << sizeof(pt3) << std::endl;
    std::cout << "Size of char pointer: " << sizeof(pt4) << std::endl;
    std::cout << "Size of Rectange struct pointer with 2 ints: " << sizeof(pt5) << std::endl;

    
    Rectangle rect = {20, 10};
    Rectangle *rectPtr = &rect;
    // No good, p is an address
    // p.length;
    // No good, this gets p.length first then dereferences it
    // *p.length;
    // Good
    std::cout << (*rectPtr).length;
    std::cout << rectPtr->length << std::endl;

    // Create on the heap
    Rectangle *rectPointer = (Rectangle *)malloc(sizeof(struct Rectangle));
    rectPointer->length = 10;
    std::cout << (*rectPointer).length;
    Rectangle *rectPointer2 = new Rectangle;

}