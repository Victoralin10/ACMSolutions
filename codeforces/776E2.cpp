#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define ll long long
#define ull long long
#define ld long double

#define MOD 1000000007
#define MAXN 1000006

using namespace std;

int A[MAXN], p[MAXN], pc = 0;

void sieve() {
    for (int i = 2; i < MAXN; i++) {
        if (!A[i]) {
            p[++pc] = i;
            A[i] = pc;
        }
        for (int j = 1; j <= A[i] && i*p[j] < MAXN; j++) {
            A[i*p[j]] = j;
        }
    }
}

ll fi(ll n) {
    ll cn = n;
    for (int i = 1; (ll)p[i]*p[i] <= cn; i++) {
        if (cn%p[i] == 0) {
            n /= p[i];
            n *= p[i] - 1;

            while (cn%p[i] == 0) {
                cn /= p[i];
            }
        }
    }
    if (cn > 1) {
        n /= cn;
        n *= cn - 1;
    }
    return n;
}

int main(int nargs, char **args) {
    sieve();

    ll n, k;
    cin >> n >> k;

    for (int i = 1; i <= k && n > 1; i += 2) {
        n = fi(n);
    }
    cout << n%MOD << endl;

    return 0;
}
