#include <iostream>
// To tell the function it's an array we must use brackets
// The function does not know size of array so we must tell the function with n
// A is not an array, it is a pointer to our array. Therefore we can directly access our array in main from here
// the array is passed by address - again A is a pointer so this is pass by address.
// Arrays cannot be passed by value
// n is passed by value of course
void fun(int A[], int n) {
    // A is a pointer to an int so sizeof(A) is 8 bytes
    // sizeof(A);

    int i;
    for (i=0;i<n;i++) {
        std::cout << A[i];
    }
    // This does not work because A is a pointer
    // for (int x:A) {
    //     std::cout << x << std::endl;
    // }
    // This changes the array in main
    A[0] = 25;
    
}
// This is valid too, the difference is here A can technically be a pointer to any int. 
// int A[] is specifically to an array of ints
void fun2(int *A, int n) {
    int i;
    for (i=0;i<n;i++) {
        std::cout << A[i];
    }
    
}

// funcion to return an array
// some compilers allow returning a straight up array but others don't
// int[] getArray - some compilers allow this instead of int*
int* getArray(int n) {
    // p is a pointer to an int. This variable lives on getArray's stack frame.
    int *p;
    // it points to memory on the heap of size of array times number of bytes an int takes
    p = (int*)malloc(n*sizeof(int));
    // We return the pointer to the heap array
    return p;
}
int *cppGetArray(int size) {
    int *p;
    p = new int[size];
    for (int i = 0;i < size;i++) {
        p[i] = i+1;
    }
    return p;
}
int getSize(int arr[]) {
    std::cout << "size of arr in function" << sizeof(arr)/sizeof(int) << std::endl;
}
int main() {
    // int A[5] = {1,2,3,4,5};
    // fun(A, 5);

    // A is a pointer to an int and lives on main's stack frame
    int *A;
    // we give array the same address the pointer that getArray returns which is the 
    // address of our array on heap
    A = getArray(5);
    
    int B[] = {1,2,3,4,5};
    getSize(B);
    std::cout << "size of arr in main" << sizeof(B) / sizeof(int) << std::endl;
    std::cout << "Size of arr in function is always 8 since arrays are passed by address by default. So whether we explicitly tell the function it's a pointer to an int or an array it will still be a pointer";

    // Quick for loop over array
    for (int x: B) {

    }
    int *ptr,sz=5;
    ptr = cppGetArray(sz);
    for (int i = 0; i < sz;i++) {
        std::cout << ptr[i] << std::endl;

    }
}