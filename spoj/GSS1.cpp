/**
* Title:            GSS1 - Can you answer these queries I
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 50004
#define oo 1<<30

using namespace std;

int A[MAXN];

struct H {
    int l, r, b, s;
    H(){}
    H(int l, int r, int b, int s):l(l), r(r), b(b), s(s){}
} T[4*MAXN];

void init(int node, int i, int j) {
    if (i == j) {
        T[node] = H(A[i], A[i], A[i], A[i]);
        return;
    }

    int izq = 2*node + 1, der = izq + 1, med = (i + j)/2;
    init(izq, i, med);
    init(der, med + 1, j);

    T[node].l = max(T[izq].l, T[izq].s + T[der].l);
    T[node].r = max(T[der].r, T[der].s + T[izq].r);
    T[node].s = T[izq].s + T[der].s;
    T[node].b = max(T[izq].r + T[der].l, max(T[izq].b, T[der].b));
}

H query(int node, int i, int j, int a, int b) {
    if (j < a || i > b) {
        return H(oo, oo, oo, oo);
    }

    if (i >= a && j <= b) {
        return T[node];
    }

    int izq = 2*node + 1, der = izq + 1, med = (i + j)/2;
    H left = query(izq, i, med, a, b);
    H right = query(der, med + 1, j, a, b);

    H ans;
    if (left.s == oo) {
        ans = right;
    } else if (right.s == oo) {
        ans = left;
    } else {
        ans.l = max(left.l, left.s + right.l);
        ans.r = max(right.r, right.s + left.r);
        ans.s = left.s + right.s;
        ans.b = max(left.r + right.l, max(left.b, right.b));
    }

    return ans;
}

int main(int nargs, char **args) {
    //clock_t _inicio = clock();

    int n, q, x, y;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    init(0, 0, n - 1);

    scanf("%d\n", &q);
    while (q--) {
        scanf("%d%d\n", &x, &y);
        printf("%d\n", query(0, 0, n - 1, x - 1, y - 1).b);
    }

    //printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
}
