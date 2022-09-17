int power(int m, int n) {
    if (n > 0) {
        return m * pow(m, n-1);
    }
    return 1;
}
int betterPower(int m, int n) {
    // O(log(n))
    if (n>0) {
        if (n % 2 == 0) {
            return betterPower(m*m, n/2)
        }
        else {
            return m * betterPower(m*m, n/2)
        }
    }
    return 1;
}
