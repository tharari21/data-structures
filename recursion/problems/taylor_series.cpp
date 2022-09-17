double taylorSeries(int x, int n) {
    static double f=1,p=1;
    double r;
    if (n > 0) {
        r = taylorSeries(z,n-1);
        p=x*p;
        f=n*f;
        return r+(p/f);
    }
    return 1;
}
double betterTaylorSeries(int x, int n) {
    static double s=1;
    if (n== 0) {
        return s;
    }
    
    s = 1+x*s/n ;
    return betterTaylorSeries(x,n-1);
}
double IterativetaylorSeries(int x, int n) {
    double s;
    int i;
    double numerator; 
    double denominator; 
    for (i=1;i<=n;i++) {
        numerator*=x;
        denominator*=i;
        s+=(numerator/denominator);
    }
    return s;
}