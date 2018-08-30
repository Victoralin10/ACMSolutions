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
#define MAXN 100

using namespace std;

int F[MAXN], G[MAXN];

int f(int n, int k) {
    if (k == 1) return F[G[n]];
    if (k%2 == 0) return G[f(n, k-1)];
    return F[f(n, k - 1)];
}

int main(int nargs, char **args) {
    // memset(mf, -1, sizeof mf);

    F[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        for (int j = 1; j < i; j++) {
            if (__gcd(j, i - j) == 1) {
                F[i]++;
            }
        }

        // cout << i << " " << F[i] << endl;
    }

    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            G[j] += F[i];
        }
        cout << i << " " << G[i] << endl;
    }

    for (int n = 1; n <= 20; n++) {
        cout << n << " ";
        for (int k = 1; k <= 20; k++) {
            cout << f(n, k) << " ";
        }
        cout << endl;
    }


    return 0;
}
