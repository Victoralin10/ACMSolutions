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

const int N = 1e5 + 5;
int A[N], B[N], L[101];

int main(int nargs, char **args) {
    int n;
    cin >> n;
    REP(i, n) scanf("%d", A + i);
    clr(L, -1);

    for (int i = n-1; i >= 0; i--) {
        int best = -1, px = n;
        for (int j = A[i] + 1; j <= 100; j++) {
            if (L[j] != -1 && L[j] < px) {
                px = L[j];
                best = j;
            }
        }
        L[A[i]] = i;
        B[i] = best;
    }

    REP(i, n) if (B[i] > 0) printf("%d%c",B[i],i+1==n?'\n':' ');
        else printf("*%c", i+1==n?'\n':' ');

    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
