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

int A[MAXN], B[MAXN];
pii T[4*MAXN];

void init(int node, int i, int j) {
    if (i == j) {
        if (A[i] > 0) T[node] = mp(0, 1);
        else T[node] = mp(1, 0);
        return;
    }

    int izq = 2*node + 1, der = izq + 1, mid = (i + j)/2;
    init(izq, i, mid);
    init(der, mid + 1, j);

    if (T[izq].se < T[der].fi) {
        T[node].fi = T[izq].fi + T[der].fi - T[izq].se;
        T[node].se = T[der].se;
    } else {
        T[node].se = T[der].se + T[izq].se - T[der].fi;
        T[node].fi = T[izq].fi;
    }
}

void update(int node, int i, int j, int px) {
    if (px < i || px > j) return;

    if (i == j) {
        A[i] = 0;
        T[node] = mp(0, 0);
        return;
    }

    int izq = 2*node + 1, der = izq + 1, mid = (i + j)/2;
    update(izq, i, mid, px);
    update(der, mid + 1, j, px);

    if (T[izq].se < T[der].fi) {
        T[node].fi = T[izq].fi + T[der].fi - T[izq].se;
        T[node].se = T[der].se;
    } else {
        T[node].se = T[der].se + T[izq].se - T[der].fi;
        T[node].fi = T[izq].fi;
    }
}

int query(int node, int i, int j, int r) {
    if (i == j) {
        return i;
    }

    int izq = 2*node + 1, der = izq + 1, mid = (i + j)/2;

    if (T[der].se > r) return query(der, mid + 1, j, r);
    return query(izq, i, mid, T[der].fi + r - T[der].se);
}

int OP[MAXN];
int XD[MAXN];

int main(int nargs, char **args) {
    int m, p, t, x;

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> p >> t;
        if (t == 0) {
            A[p] = -1;
            OP[i-1] = p;
        } else {
            cin >> x;
            B[p] = x;
            A[p] = 1;
            OP[i-1] = p;
        }
    }

    init(0, 1, m);
    // for (int i = 0; i < 3; i++) {
    //     cout << T[i].fi << " " << T[i].se << endl;
    // }

    for (int i = m - 1; i >= 0; i--) {
        // cout << query(0, 1, m, 0) << endl;
        if (T[0].se > 0) XD[i] = B[query(0, 1, m, 0)];
        else XD[i] = -1;
        update(0, 1, m, OP[i]);
    }

    for (int i = 0; i < m; i++) {
        cout << XD[i] << endl;
    }

    return 0;
}
