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
#define MAXN 500005

using namespace std;

int T[4*MAXN], V[MAXN];


void init(int nd, int i, int j) {
    if (i == j) {
        T[nd] = V[i];
        return;
    }

    int izq = 2*nd + 1, der = izq + 1, mid = (i + j)/2;
    init(izq, i, mid);
    init(der, mid + 1, j);
    T[nd] = __gcd(T[izq], T[der]);
}

int a, b, nv, x;

void update(int nd, int i, int j) {
    if (a < i || a > j) {
        return;
    }
    if (i == j) {
        T[nd] = x;
        return;
    }

    int izq = 2*nd + 1, der = izq + 1, mid = (i + j)/2;
    update(izq, i, mid);
    update(der, mid + 1, j);
    T[nd] = __gcd(T[izq], T[der]);
}

int query(int nd, int i, int j) {
    // cout << nd << " " << i << " " << j << endl;
    if (i > b || j < a) {
        return 0;
    }

    if (T[nd]%x == 0) {
        return 0;
    }

    if (i == j) {
        return T[nd]%x != 0;
    }

    int izq = 2*nd + 1, der = izq + 1, mid = (i + j)/2;
    int ai = query(izq, i, mid);
    if (ai > 1) return 2;
    ai += query(der, mid + 1, j);
    return ai;
}

int main(int nargs, char **args) {
    int n, q, t;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", V +  i);
    }
    init(0, 0, n);

    cin >> q;
    while (q--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &a, &b, &x);
            // cout << query(0, 0, n) << endl;
            puts(query(0, 0, n)<=1?"YES":"NO");
            // return 0;
        } else {
            scanf("%d%d", &a, &x);
            update(0, 0, n);
        }
    }
    return 0;
}
