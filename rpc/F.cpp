#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;

const int N = 4e2 + 2;

bool vis[N][N];
double M[N][N];

double f(int n, int k) {
    if (!k) {
        return 0;
    }
    if (n == 1) {
        return 0.5;
    }
    if (vis[n][k]) {
        return M[n][k];
    }
    vis[n][k] = 1;
    return M[n][k] = 0.5*(1 + f(n - 1, k - 1) + f(n, k - 1));
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    int n, k;
    cin >> n >> k;
    clr(vis, 0);
    printf("%.6f\n", f(n, k));

    // fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
