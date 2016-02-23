#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1005

using namespace std;

int D[MAXN], T[MAXN];
int DP[MAXN][MAXN], N[MAXN][MAXN];

int main(int n, char **args) {
    clock_t _inicio = clock();

    bool first = true;
    int t, w, nt;
    while (cin >> t >> w) {
        cin >> nt;
        for (int i = 1; i <= nt; i++) {
            cin >> D[i] >> T[i];
        }

        for (int i = 0; i <= nt; i++) {
            int need = 3*w*D[i];
            for (int j = 0; j <= t; j++) {
                DP[i][j] = DP[i-1][j];
                N[i][j] = j;
                if (need <= j && DP[i][j] < DP[i-1][j-need] + T[i]) {
                    DP[i][j] = DP[i-1][j-need] + T[i];
                    N[i][j] = j-need;
                }
            }
        }

        if (!first) {
            cout << endl;
        }
        first = false;

        cout << DP[nt][t] << endl;
        vector <pair<int, int> > ans;
        for (int i = nt, ta = t; i >= 0; i--) {
            if (t != N[i][t]) {
                ans.push_back(make_pair(D[i],T[i]));
            }
            t = N[i][t];
        }
        cout << ans.size() << endl;
        for (int i = (int)ans.size() - 1; i >= 0; i--) {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }

    //printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
}
