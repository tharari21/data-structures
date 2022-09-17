#include <iostream>
int fib(int n) {
    // excessive recursion
    if (n<=1) {
        // if n=0 return 0 or if n=1 return 1 
        return n;
    }
    return fib(n-1) + fib(n-2);
}
int F[20];
int e=0;
int fibWithoutExcessiveRecursion(int n){
    // Our fib function makes redundant calls so to fix this we keep an array that tracks already called values
    // Use memoization

    std::cout << e << std::endl;
    e++;
    if (n<=1) {
        return n;
    }
    if (F[n-2] == -1) {
        F[n-2] = fibWithoutExcessiveRecursion(n-2);
    }
    if (F[n-1] == -1) {
        F[n-1] = fibWithoutExcessiveRecursion(n-1);
    }
    // This is not doing anything it simply ensures that the root call of n is in the final array with it's value as well but in terms of solving the problem it does not add anything
    F[n] = F[n-2] + F[n-1];
    return F[n];
    
}
int main() {
    // Initialize F
    int i;
    for (i=0;i<20;i++) {
        F[i] = -1;
    }

    std::cout << fibWithoutExcessiveRecursion(20);
    /*
Pointers have no default value. The value they have is just whatever junk was in the memory they're using now. Sometimes a specific compiler will zero out memory, but that's not standard so don't count on it.)

The memory from malloc being NULL was a coincidence; it could have been any other value just as easily. You need to and should always manually set all your pointers to NULL.

Another alternative is you can also use calloc, which does the same thing as malloc but sets all bits to 0 in the block of memory it gives you. This doesn't help with stack variables though, so you still have to set those to NULL by yourself.


    */
    int *p;
    std::cout << *p << std:: endl;


}
int iterativeFib(int n) {
    int t0=0,t1=1,s=0;
    if (n<=1) {
        return n;
    }
    for (int i=2;i<=n;i++) {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}