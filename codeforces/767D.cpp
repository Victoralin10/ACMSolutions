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
#define MAXN 1000006

using namespace std;

int n, m, k;
int F[MAXN];
pair <int, int> S[MAXN];

vector <pair<int, int> > A;
int D[10*MAXN];

int main(int nargs, char **args) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &F[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &S[i].fi);
        // S[i].fi = -S[i].fi;
        S[i].se = i + 1;
    }
    sort(F, F + n);
    sort(S, S + m);

    bool ok = 1;
    for (int i = n-1, j, d = F[n-1]; i >= 0;) {
        j = i;
        while (j >= 0 && F[i] == F[j]) {
            j--;
        }
        int xd = i - j;
        d = min(d, F[i]);
        while (xd > 0 && d >= 0) {
            int tmp =min(k - D[d], xd); 
            D[d] += tmp;
            xd -= tmp;
            d--;
        }
        if (xd > 0) {
            ok = 0;
            break;
        }
        i = j;
    }

    if (!ok) {
        puts("-1");
    } else {
        vector <int> ans;
        for (int i = 0, j = 0; j < m; j++) {
            while (D[i] >= k) i++;
            if (i > S[j].fi) continue;
            D[i]++;
            ans.pb(S[j].se);
        }

        printf("%d\n", ans.size());
        for (int i = (int)ans.size() - 1; i >= 0; i--) {
            printf("%d%c", ans[i], i?' ':'\n');
        }
    }


    return 0;
}
