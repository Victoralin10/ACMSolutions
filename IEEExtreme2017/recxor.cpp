#include <iostream>

using namespace std;

long long f(long long n) {
    int r = n%4;
    if (r == 0) return n;
    if (r == 3) return 0;
    if (r == 2) return n+1;
    return 1;
}

long long fi(long long a, long long b) {
    return f(b)^f(a-1);
}

int main() {
    int t, r1, r2, c1, c2;
    long long l, h, n, d1, d2;
    cin >> t;
    while (t--) {
        cin >> l >> h >> n >> d1 >> d2;
        r1 = (d1 - n)/l;
        r2 = (d2 - n)/l;
        c1 = (d1 - n)%l;
        c2 = (d2 - n)%l;
        if (c1 > c2) swap(c1, c2);

        // cout << r1 << " " << r2 << endl;
        // cout << c1 << " " << c2 << endl;

        long long xi = 0;
        for (long long i = r1; i <= r2; i++) {
            xi ^= fi(i*l + c1 + n, i*l + c2 + n);
        }

        cout << (fi(n, n + (long long)h*l - 1)^xi) << endl;
    }
    return 0;
}