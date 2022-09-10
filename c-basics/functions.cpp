int add(int a, int b) {
    // If your finction simply performs a calculation and returns a value, use pass by value
    int c;
    c = a+b;
    return c;
}
void swap(int x, int y) {
    //pass by value
    // Does not actually swap. It swaps x and y in the function but the parameters
    // passed are not swapped
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void swap2(int *x, int *y) {
    //pass by address
    /*
    When passing a pointer to a function, you are still passing it by value. The address it contains is copied into the function. Modifying that pointer inside the function will not change the pointer outside the function - however, modifying the object it points to will change the object outside the function. But why?
    As two pointers that have the same value always point at the same object (they contain the same address), the object that is being pointed to may be accessed and modified through both.
    */

    // Actually swaps. x and y can now indirectly access the variables in main
    int temp;
    // asigns temp to value of what x is pointing to 
    temp = *x;
    // assigns value x is pointing to to value y is pointing to
    *x = *y;
    // assigns value y is pointing to to temp
    *y = temp;
}
void swap3(int &x, int &y) {
    //pass by reference (only in c++)
    //the beauty of this is the method body is same as 
    // og swap that's pass by value only thing that changes is the parameters are references.
    // We also pass the function values
    // it also does not take additional memory - in pass by address we store pointers which are 8 bytes each.
    // here we simply alias the variable which takes no additional space
    // behind the scenes, this function's code is copied into the code where swap3 is called in main
    // The compiler makes all our code monolithic rather than procedural when calling functions that pass by refeence.
    // What monolithic means is all our code in one function rather than procedural where different functions are called separately
    // The reason it does this is if swap3 were on a different stack frame from main, then we could not access memory of main
    // in swap3 so c++ brings this code into main and then they are on the same stack frame.
    // Apparently the copying of this function into main is only a thing on some compilers depends how they handle references as parameters.
    // It either copies swap3's code to be inline in main or it will convert the references to pointers.
    // We can't tell for sure unless we check compiler code


    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main() {
    int x,y,z;
    x =10;
    x=10;
    // currentlly x,y and z are on main stack frame. When add is called, add stack frame
    // will be added to stack. in this add stack frame a b and c variables are created and values 
    // of x and y are passed into a and b of add and at the end value of c is passed to main stack frame. 
    // Stack frame for add is then deleted and control is handed back to main
    z = add(x,y);
    swap(x,y);
    swap2(&x,&y);
    swap3(x,y);
}