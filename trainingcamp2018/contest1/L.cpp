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

double memo[1<<21], p[21];
int n, k;

double dp(int mask) {
    if (mask == 0) return 1;
    if (memo[mask] >= 0) return memo[mask];
    if (__builtin_popcount(mask) > n) {
        return memo[mask] = 0;
    }

    double &ans = memo[mask];
    ans = 0;

    

    return ans;
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }

    if (n >= k) {
        for (int i = 0; i < k; i++) {
            printf("%.8f%c", p[i], (i+1==k?'\n':' '));
        }
        return 0;
    }

    for (int mask = (1<<k) - 1; mask > 0; mask--) {
        memo[mask] = -1.0;
    }

    vector <double> A(k, 0.0);
    REP(i, 1<<k) {
        REP(j, k) {
            if ((i&(1<<j)) > 0) {
                A[j] += dp(i);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        printf("%.8f%c", A[i], (i+1==k?'\n':' '));
    }

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
