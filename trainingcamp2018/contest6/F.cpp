#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;

uint p[5000006], uni = 1, mod = UINT_MAX;

bool query(int x) {
    return !(p[x>>5]&(uni<<(x&31)));
}

void set(int x, bool v) {
    uint a = (uni<<(x&31));
    if (!v) p[x>>5] |= a;
    else p[x>>5] &= ~a;
}

int rev(int a) {
    return a*3 + 1 + (a&1);
}

int n, a, b, c, d;

void add(ull &ans, uint x, uint b) {
    ans *= x;
    ans &= mod; 
    ans += b;
    ans &= mod;
}

uint f(uint x) {
    ull ans = a;
    add(ans, x, b);
    add(ans, x, c);
    add(ans, x, d);
    return ans;
}

void addsum(int n, int p, ull val, ull &ans) {
    while (n) {
        ans += val*(n/p);
        ans &= mod;
        n /= p;
    }
    ans &= mod;
}

int fmod(int a, int b) {
    return a - b*(a/b);
}

int main(int nargs, char **args) {
    cin >> n >> a >> b >> c >> d;

    for (int i = 6, k, p, r = sqrt(n + 0.5), x; i <= r; i += 6) {
        for (k = -1; k < 2; k += 2) {
            p = i + k, x;
            if (query(p/3)) {
                for (int j = p*p; j <= n; j += p) {
                    x = fmod(j, 6);
                    if (x != 1 && x != 5) continue;
                    set(j/3, false);
                }
            }
        }
    }

    set(0, false);
    ull ans = 0;
    if (n > 1) addsum(n, 2, f(2), ans);
    if (n > 2) addsum(n, 3, f(3), ans);

    bool ok = 1;
    for (int i = 0, j, pr; ok; i++) {
        uint mk = p[i];
        for (j = 0; j < 32; j++) {
            if (!(mk&1)) {
                pr = rev((i<<5) + j);
                if (pr > n) {
                    ok = 0;
                    break;
                }
                addsum(n, pr, f(pr), ans);
            }
            mk >>= 1;
        }
    }

    cout  << ans << endl;

    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
