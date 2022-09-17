int factorial(int n) {
    if (n > 0) {
        return n * factorial(n-1);
    }
    return 1;
}
