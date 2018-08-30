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
#define MAXN 110

using namespace std;

int A[MAXN], B[MAXN];

int main(int nargs, char **args) {
    int l, n;
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    bool ans = 0;
    for (int i = 0; i <= l; i++) {
        bool ok = 1;
        for (int j = 0; j < n; j++) {
            B[j] = (B[j] + 1)%l;
        }

        sort(B, B + n);
        for (int j = 0; j < n; j++) {
            ok = ok && (B[j] == A[j]);
        }

        if (ok) {
            ans = 1;
            break;
        }
    }

    cout << (ans?"YES":"NO") << endl;

    return 0;
}
