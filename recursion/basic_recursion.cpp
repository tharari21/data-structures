#include <iostream>
void ascendingRecursiveFunction(int n) {
    if (n>0) {
        // Operation occurs during calling phase
        std::cout << n << std::endl;
        ascendingRecursiveFunction(n-1);
    }
}
void descendingRecursiveFunction(int n) {
    if (n>0) {
        descendingRecursiveFunction(n-1);
        // Operation occurs during returning phase
        std::cout << n << std::endl;
    }
}

int main() {
    std::cout << "Calling phase (ascending) recursive function: \n";
    ascendingRecursiveFunction(5);
    std::cout << "\nreturning phase (descending) recursive function: \n";
    descendingRecursiveFunction(5);
}