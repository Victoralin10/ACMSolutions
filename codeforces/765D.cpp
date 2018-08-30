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
#define MAXN 100005

using namespace std;

bool ok[MAXN];
int F[MAXN], G[MAXN], H[MAXN], M[MAXN], m = 0;

int main(int nargs, char **args) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> F[i];
        if (i == F[i]) {
            ok[i] = 1;
            M[i] = ++m;
            H[m] = i;
        }
    }

    bool ok1 = 1;
    for (int i = 1; i <= n && ok1; i++) {
        if (!ok[F[i]]) {
            ok1 = 0;
            break;
        }
        G[i] = M[F[i]];
    }

    if (!ok1) {
        puts("-1");
    } else {
        cout << m << endl;
        for (int i = 1; i <= n; i++) {
            printf("%d%c", G[i], i==n?'\n':' ');
        }
        for (int i = 1; i <= m; i++) {
            printf("%d%c", H[i], i==m?'\n':' ');
        }
    }

    return 0;
}
