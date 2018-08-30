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

int w[15];
char S[15];
int MC[1<<12], CK[1<<12][105], A[1<<12][105];

int main(int nargs, char **args) {
    int n, q, m, k;
    cin >> n >> m >> q;
    REP(i, n) {
        cin >> w[i];
    }
    REP(i, m) {
        scanf("%s", S);
        int x = 0;
        for (int j = n-1; j >= 0; j--) {
            x = (x<<1) + (S[j] - '0');
        }
        MC[x]++;
    }

    REP(i, (1<<12)) {
        if (!MC[i]) continue;
        REP(j, (1<<12)) {
            int sum = 0, an = i^j;
            REP(k, n) {
                if ((an&(1<<k)) == 0) {
                    sum += w[k];
                }
            }
            sum = min(sum, 102);
            CK[j][sum] += MC[i];
        }
    }

    REP(j, (1<<12)) {
        int cnt = 0;
        REP(i,101) {
            cnt += CK[j][i];
            A[j][i] = cnt;
        }
    }

    while (q--) {
        scanf("%s%d", S, &k);
        int x = 0;
        for (int j = n-1; j >= 0; j--) {
            x = (x<<1) + (S[j] - '0');
        }
        printf("%d\n", A[x][k]);
    }

    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
