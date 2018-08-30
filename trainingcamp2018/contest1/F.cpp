#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

clock_t _inicio = clock();

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

#define MAXN 200005

struct Node {
    int F[101];
    bool id;
    Node() {
        reset();
    }
    void reset() {
        id = true;
        REP(i, 101) {
            F[i] = i;
        }
    }
};

Node T[4*MAXN], tmp;
int A[MAXN];

void compose(int x, int y, Node &a) {
    if (a.id) {
        a.F[x] = y;
        a.id = (x == y);
    } else {
        REP(i, 101) {
            tmp.F[i] = a.F[i];
            if (tmp.F[i] == x) {
                tmp.F[i] = y;
            }
        }
        a.id = false;
        memcpy(a.F, tmp.F, sizeof(tmp.F));
    }
}

void compose(Node &a, Node &b) {
    if (b.id) {
        memcpy(b.F, a.F, sizeof(a.F));
    } else {
        REP(i, 101) {
            tmp.F[i] = a.F[b.F[i]];
        }
        memcpy(b.F, tmp.F, sizeof(tmp.F));
    }
    b.id = false;
}

void update(int node, int i, int j, int a, int b, int x, int y) {
    if (j < a || i > b) {
        return;
    }
    if (i == j) {
        compose(x, y, T[node]);
        return;
    }
    if (i >= a && j <= b) {
        compose(x, y, T[node]);
        return;
    }

    int izq = 2*node + 1, der = izq + 1, mid = (i + j)>>1;
    if (!T[node].id) {
        compose(T[node], T[izq]);
        compose(T[node], T[der]);
        T[node].reset();
    }
    update(izq, i, mid, a, b, x, y);
    update(der, mid + 1, j, a, b, x, y);
}

void flush(int node, int i, int j) {
    if (i == j) {
        A[i] = T[node].F[A[i]];
        return;
    }

    int izq = 2*node + 1, der = izq + 1, mid = (i + j)>>1;
    if (!T[node].id) {
        compose(T[node], T[izq]);
        compose(T[node], T[der]);
    }
    flush(izq, i, mid);
    flush(der, mid + 1, j);
}

int main(int nargs, char **args) {
    int n, q, l, r, x, y;
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", A + i);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d", &l, &r, &x, &y);
        update(0, 0, n - 1, l - 1, r - 1, x, y);
    }
    flush(0, 0, n - 1);
    REP(i, n) {
        printf("%d%c", A[i], (i+1==n?'\n':' '));
    }

    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
