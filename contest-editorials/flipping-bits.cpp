/*
 * Question Link: https://www.hackerrank.com/contests/itu-acm-algo-101-contest-22-23/challenges/flipping-bits
 *
 * One thing to notice about this problem is that flipping a bit is the equivalent of taking its xor with 1.
 *
 * Proof:
 * 1 ^ 1 = 0
 * 0 ^ 1 = 1
 * 
 * To perfom this easly, we can use bitsets.
 * 
 * Time Complexity: O(1) ---> we operate on a constant number of digits (32)
 * 
 * Space Complexity: O(1)
 */

#include <bits/stdc++.h>

using namespace std;

long flippingBits(long n) {

    bitset<32> b1;
    b1.set(); // this method initializes all bits to 1
    
    bitset<32> b2 = n; // convert decimal number to binary
    
    return (b1 ^ b2).to_ulong(); // xor both binary numbers and convert to unsigned long integer
}

int main()
{
    long long q;
    cin >> q;

    while (q--) {
        long long n;
        cin >> n;

        cout << flippingBits(n) << endl;
    }

    return 0;
}
