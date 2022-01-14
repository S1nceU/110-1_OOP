#ifndef GCD_H
#define GCD_H
// return the (positive) greatest common divisor of two integers
// a, b may be positive or negative
int gcd(int a, int b) {
    int t;
    a = abs(a);
    b = abs(b);
    while (b != 0){
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}
#endif