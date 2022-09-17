#include <iostream>
void tailRecursion(int n) {
    if (n>0) {
        std::cout << n << std::endl;
        // Any number of operations can go here, before the recursive call for it to be tail recursion
        tailRecursion(n-1);
        // if this were the recursive call, this would not be tail recursion since the +n occurs during returning phase
        // tailRecursion(n-1)+n;
    }
}
void tailRecursionAsLoop(int n) {
    // To show that tail recursion can easily be transformed to a loop.
    // Time complexity is same for recursive and iterative-O(n)
    // Space complexity for recursive function is O(n) but here it is O(1).
    // So the conclusion is that with tail recursion, the iterative approach is better than recursive always
    // Because the time complexity is the same but storage is no good for recursion
    while (n>0) {
        std::cout << n << std::endl;
        n--;
    }
}
void headRecursion(int n) {
    if (n>0) {
        // If any code goes above recursion call this no longer is headRecursion
        headRecursion(n-1);
        std::cout << n;
    }
}
void headRecursionAsLoop(int n) {
    // This will get same result as head recursive function but the style is different so harder to directly translate
    // Space complexity here is better as well since no activation records are created
    int i=1;
    if (i<=n) {
        std::cout << n;
        i++;
    }
}
void linearRecursion(int n) {
    // A linear recursion only calls itself one time
    // linear recursion is not head or tail recursion since it has statements before and after recursive call. 
    // Note that head and tail recursion are also linear
    if (n>0) {
        std::cout << n << std::endl;
        linearRecursion(n-1);
        std::cout << n << std::endl;
    }
}

void treeRecursion(int n) {
    // Draw this out as a tree to help
    if (n>0) {
        std::cout << n << std::endl;
        treeRecursion(n-1);
        // prints 1 to n up until this point during call phase
        // now during returning phase for each we enter a call phase
        treeRecursion(n-1);
    }
}

// Indirect recursion
namespace IndirectRecursion {
    void funB(int n);
    void funA(int n) {
        if (n > 0) {
            std::cout << n << std::endl;
            IndirectRecursion::funB(n-1);
        }
    }
    void funB(int n) {
            if (n>1) {
                std::cout << n << std::endl;
                funA(n/2);
            }
    }
}
int nestedRecursion(int n) {// The function returns 91 for any n less than or equal to 100 otherwise it returns n-10
    
    std::cout << "New stack " << n  << std::endl;
    if (n>100) {
        
        return n-10;
    }
    // Inner is called untill n+11 > 100
    // When n+11 > 100 then we start going to the return phase of inner function
    // During return phase of inner function we start going into calling phase of outer function
    // the outer function gets called on n+11 that was > 100
    // Then th
    return nestedRecursion(nestedRecursion(n+11));
}

int main() {
    IndirectRecursion::funA(20);
    nestedRecursion(0);

}