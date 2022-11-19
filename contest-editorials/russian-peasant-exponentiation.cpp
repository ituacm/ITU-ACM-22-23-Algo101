/*
 * Question Link: https://www.hackerrank.com/contests/itu-acm-algo-101-contest-22-23/challenges/russian-peasant-exponentiation
 *
 * What differs this problem from a common fast exponentiation problem is that is requires extra calculations considering the rules of complex numbers:
 *
 * Assume we have two complex numbers c1, c2 such that (c1 = a * bi) and (c2 = c * di) .
 * c1 * c2 = (a * c - b * d) + (a * d + b * c) * i
 * (Notice that i^2 = -1)
 * 
 * Remembering this rule, we construct a class to represent complex numbers and store real and imaginary coefficients.
 * 
 * Time Complexity: O(logk) ---> k denotes the power
 * 
 * Space Complexity: O(1) ---> allocated memory does not grow proportionally to the input size.
 */

#include<bits/stdc++.h>

using namespace std;

class Complex{
    public:
    long long real;
    long long img;

    Complex();
    // default constructor for Complex object. Sets both coefficients to 0.

    Complex(long long, long long);
};

Complex::Complex() {
    this->real = 0;
    this->img = 0;
}

Complex::Complex(long long real, long long img) {
    this->real = real;
    this->img = img;
}

Complex* multiply(Complex* a, Complex* b, long long mod) {
    // this utility function multiplies two complex numbers according to the formula described above.

    Complex* res = new Complex();

    res->real = (a->real * b->real - a->img * b->img) % mod; // Notice that we take modulo at every step to avoid overflow.
    res->img = (a->img * b->real + a->real * b->img) % mod;

    return res;
}

Complex* fastExp(Complex* a, long long power, long long mod) {
    // this is the fast exponentiation (russian peasant exponentiation) algorithm mentioned in the problem description.
    // for detailed explanation of th algorithm please visit http://lafstern.org/matt/col3.pdf
    Complex* answer = new Complex(1, 0);

    while (power > 0) {
        if (power & 1) {
            answer = multiply(answer, a, mod);
        }

        a = multiply(a, a, mod);
        power /= 2;
    }

    return answer;
}

int main() {

    long long t;

    cin >> t;

    while (t--) {
        long long a, b, k, mod;
        cin >> a >> b >> k >> mod;

        Complex* c = new Complex(a, b);

        Complex* answer = fastExp(c, k, mod);
        cout << (answer->real + mod) % mod << " " << (answer->img + mod) % mod << endl;
    }

    return 0;
}
