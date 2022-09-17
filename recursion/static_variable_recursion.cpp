#include <iostream>
int summation(int n) {
    // Gets sum of all numbers 1 through n
    if (n>0) {
        // This will add summation activation record to stack until n=0
        // When n hits 0, summation(n-1) returns 0 and n is 1
        // 1 is passed to previous caller which was n=2 2+1=3 is returned to previous caller
        // n is 3 so 3 + summation(2)=3 is 6
       return summation(n-1) + n;
    }
    return 0;
}
int staticVariableSum(int n) {
    // x is static so it is stored in the memory of all the code we write and is not redefined every call to this function. Only initialized once
    static int x = 0;
    if (n>0) {
        x++; // x is incremented each time during calling phase. Then during returning phase, only line 19 is called which adds x to each returned value we get.
        // So durning first run x is 1 then 2, etc. til 5. x is constantly 5 during returning phase.
        return staticVariableSum(n-1) + x;
    }
    return 0;
}
int g=0;
int globalVariableSum(int n) {
    // Global variables work the same way as static
    if (n>0) {
        g++; 
        return globalVariableSum(n-1) + g;
    }
    return 0;
}



int main() {
    std::cout <<summation(3) << std::endl;
    std::cout << staticVariableSum(5) << std::endl;
    std::cout << globalVariableSum(5);
    
}