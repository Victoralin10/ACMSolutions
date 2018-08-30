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

int n, q;
double v[MAXN];

double T[4*MAXN], M[4*MAXN], S[4*MAXN];

void flush(int node, int izq, int der) {
    M[izq] *= M[node];
    S[izq] = S[izq]*M[node] + S[node];
    M[der] *= M[node];
    S[der] = S[der]*M[node] + S[node];
    M[node] = 1;
    S[node] = 0;
}

void init(int node, int i, int j) {
    if (i == j) {
        T[node] = v[i];
        M[node] = 1;
        S[node] = 0;
        return;
    }

    int izq = 2*node + 1, der = izq + 1, mid = (i + j)/2;
    M[node] = 1;
    S[node] = 0;
    init(izq, i, mid);
    init(der, mid + 1, j);
    T[node] = T[izq] + T[der];
}

void update(int node, int i, int j, int a, int b, double m, double s) {
    if (b < i || a > j) {
        return;
    }

    if (i >= a && j <= b) {
       M[node] *= m;
       S[node] = S[node]*m + s;
       T[node] = T[node]*M[node] + (j - i + 1)*S[node];
       M[node] = 1; S[node] = 0;
       return;
    }

    int izq = 2*node + 1, der = izq + 1, mid = (i + j)/2;
    T[node] = T[node]*M[node] + (j - i + 1)*S[node];
    flush(node, izq, der);

    update(izq, i, mid, a, b, m, s);
    update(der, mid + 1, j, a, b, m, s);
    T[node] = T[izq] + T[der];
}

double query(int node, int i, int j, int a, int b) {
    if (b < i || a > j) {
        return 0;
    }
    int izq = 2*node + 1, der = izq + 1, mid = (i + j)/2;
    T[node] = T[node]*M[node] + (j - i + 1)*S[node];
    flush(node, izq, der);

    if (i >= a && j <= b) {
        return T[node];
    }

    return query(izq, i, mid, a, b) + query(der, mid + 1, j, a, b);
}

int main(int nargs, char **args) {
    scanf("%d%d", &n, &q);
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        v[i + 1] = x;
    }

    init(0, 0, n);
    int t, l1, r1, l2, r2;
    double le1, le2, su1, su2;
    while (q--) {
        scanf("%d%d%d", &t, &l1, &r1);
        if (t == 1) {
            scanf("%d%d", &l2, &r2);
            le1 = r1 - l1 + 1; le2 = r2 - l2 + 1;
            su1 = query(0, 0, n, l1, r1);
            su2 = query(0, 0, n, l2, r2);
            update(0, 0, n, l1, r1, 1 - 1/le1, su2/(le1*le2));
            update(0, 0, n, l2, r2, 1 - 1/le2, su1/(le1*le2));
        } else {
            printf("%.6f\n", query(0, 0, n, l1, r1));
        }
    }

    return 0;
}
