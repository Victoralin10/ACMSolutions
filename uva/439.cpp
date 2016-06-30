/**
* Title:            439 - Knight Moves
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

bool vis[MAXN][MAXN];
int D[MAXN][MAXN];

int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int solve(int r0, int c0, int r1, int c1) {
    memset(D, 0, sizeof D);
    memset(vis, 0, sizeof vis);

    queue <pair <int, int> > Q;
    Q.push(make_pair(r0, c0));
    vis[r0][c0] = true;

    while (!Q.empty()) {
        pair <int, int> q = Q.front();
        Q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = q.first + dr[i];
            int nc = q.second + dc[i];

            if (isValid(nr, nc) && !vis[nr][nc]) {
                D[nr][nc] = D[q.first][q.second] + 1;
                vis[nr][nc] = true;
                Q.push(make_pair(nr, nc));
            }
        }
    }

    return D[r1][c1];
}



int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    string a, b;
    while (cin >> a >> b) {
        int ans = solve(a[0] - 'a', a[1] - '1', b[0] - 'a', b[1] - '1');
        cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves." << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
