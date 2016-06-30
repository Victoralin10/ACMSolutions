/**
* Title:            10803 - Thunder Mountain
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

double dist(pair <int, int> a, pair <int, int> b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    return sqrt(x*x + y*y);
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int tc;
    cin >> tc;

    for (int caso = 1; caso <= tc; caso++) {
        int n;
        cin >> n;
        vector <pair <int, int> > towns;

        for (int i = 0, x, y; i < n; i++) {
            cin >> x >> y;
            towns.push_back(make_pair(x, y));
        }

        vector <vector <double> > D(n, vector <double> (n, (1<<30)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist(towns[i], towns[j]) <= 10) {
                    D[i][j] = dist(towns[i], towns[j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
                }
            }
        }

        bool ok = true;
        double ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (D[i][j] > 10000) {
                    ok = false;
                }
                ans = max(ans, D[i][j]);
            }
        }

        cout << "Case #" << caso << ":" << endl;
        if (ok) {
            printf("%.4f\n\n", ans);
        } else {
            cout << "Send Kurdy" << endl << endl;
        }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
