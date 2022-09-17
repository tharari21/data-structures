int sumOfFirstN(int n) {
    if (n > 0) {
        return n+sumOfFirstN(n-1);
    }
    return 0;
}