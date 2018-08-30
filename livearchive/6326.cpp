/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 101

using namespace std;

int M[MAXN][MAXN];
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool isValid(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t, n, m;
    cin >> t;

    while (t--) {
      cin >> n >> m;

      for (int i = 0;i < n;i++) {
        for (int j = 0;j < m; j++) {
          cin >> M[i][j];
        }
      }

      map <int, bool> mp;

      for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
          for (int k = 0;k < 8;k++) {
            if (M[i][j] < 0) continue;
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (isValid(n, m, ni, nj) && M[i][j] == M[ni][nj]) {
              mp[M[i][j]] = true;
            }
          }
        }
      }

      int ans = 0;
      for (map<int, bool>::iterator it = mp.begin();it != mp.end(); it++) {
        if (it->second) {
          ans++;
        }
      }
      cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
