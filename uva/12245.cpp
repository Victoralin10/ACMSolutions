#include <bits/stdc++.h>
#define MOD 100000000
#define MAXN 106

using namespace std;
pair <int, int> P[MAXN];
int DP[MAXN][MAXN];

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    P[0] = make_pair(-100, -10);
    P[1] = make_pair(-10, 0);

    int m, n, mx;
    while (cin >> m >> n) {
        if (n + m <= 0) break;

        mx = -1;
        n += 2;
        for (int i = 2; i < n; i++) {
            cin >> P[i].first >> P[i].second;
            mx = max(mx, P[i].second);
        }
        P[n++] = make_pair(m, m + 10);
        P[n++] = make_pair(m+10, m + 20);

        sort(P, P + n);
        if (P[2].first > 0 || mx < m) {
            cout << 0 << endl;
            continue;
        }

        DP[1][0] = 1;
        for (int i = 2; i < n; i++) {
            for (int j = i-1; j > 0; j--) {
                DP[i][j] = 0;
                if (P[j].first >= P[i].first || P[j].second < P[i].first) {
                    continue;
                }
                for (int k = j-1; k >= 0; k--) {
                    if (P[k].first < P[j].first && P[k].second >= P[j].first
                        && P[k].second < P[i].first) {

                        //cout << i << " " << j << " " << k << endl;
                        DP[i][j] += DP[j][k];
                        if (DP[i][j] >= MOD) DP[i][j] -= MOD;
                    }
                }
            }
        }

        cout << DP[n-1][n-2] << endl;
    }

    //printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
}
