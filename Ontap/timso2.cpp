#include <bits/stdc++.h>
using namespace std;

// H�m t�nh t�ch c�c ch? s? c?a s? n
long long tich(long long n) {
    long long product = 1;
    while (n > 0) {
        product *= (n % 10);
        n /= 10;
    }
    return product;
}

// H�m t�m s? nguy�n duong K nh? nh?t
long long findK(long long m) {
    if (m == 0) return 10; // Tru?ng h?p d?c bi?t: M = 0, K = 10 (v� 1 * 0 = 0)
    if (m < 10) return m;  // Tru?ng h?p d?c bi?t: M < 10, K = M (v� ch? c?n s? M)

    // S? d?ng stack d? t�m K t? c�c ch? s? nh? nh?t
    stack<int> digits;
    for (int d = 9; d >= 2; d--) { // Duy?t t? 9 d?n 2
        while (m % d == 0) {
            digits.push(d);
            m /= d;
        }
    }
    
    if (m > 1) return -1; // Kh�ng th? ph�n t�ch M th�nh t�ch c�c ch? s?
    
    // T?o s? K nh? nh?t t? c�c ch? s? trong stack
    long long K = 0;
    while (!digits.empty()) {
        K = K * 10 + digits.top();
        digits.pop();
    }
    return K;
}

int main() {
    long long m;
    cin >> m;
    cout << findK(m) << endl;
    return 0;
}

