#include <cstdio>
#include <set>

#define MOD 1000000007
#define MAXN 1003

using namespace std;

int M[4][MAXN];

long long fastpow(long long b, int e) {
    long long ans = 1;
    while (e) {
        if ((e&1)) ans = ans*b % MOD;
        e >>= 1;
        b = b*b % MOD;
    }
    return ans;
}

int main(int nargs, char **args) {
    int t, n;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf("%d", &n);
        long long sum = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &M[i][j]);
                sum += M[i][j];
            }
        }

        if (sum%n != 0) {
            printf("Case %d: No\n", caso);
            continue;
        }
        int target = sum/n;

        set <int> st;
        for (int i = 0; i < n; i++) {
            int hash = 0;
            for (int j = 0; j < n; j++) {
                hash = ((long long)hash*n + (target - M[0][j] - M[1][(i + j)%n])) % MOD;
            }
            st.insert(hash);
        }

        bool ok = 0;
        long long nn = fastpow(n, n);
        for (int i = 0; i < n && !ok; i++) {
            int hash = 0;
            for (int j = 0; j < n; j++) {
                hash = ((long long)hash*n + M[2][j] + M[3][(i + j)%n]) % MOD;
            }
            for (int j = 0; j < n && !ok; j++) {
                if (st.find(hash) != st.end()) {
                    ok = 1;
                }
                hash = ((long long)hash*n + M[2][j] + M[3][(i + j)%n]) % MOD;
                hash = (hash - (M[2][j] + M[3][(i + j)%n])*nn)% MOD;
                if (hash < 0) hash += MOD;
            }
        }

        printf("Case %d: %s\n", caso, (ok?"Yes":"No"));
    }
    return 0;
}
