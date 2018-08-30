#include <bits/stdc++.h>

using namespace std;

#define MAXN 1003

int t, w, h;
char M[MAXN][MAXN], CM[MAXN][MAXN];

int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc[] = {1, -1, 0, 0, 1, -1, 1, -1};

bool valid(int r, int c) {
    return r >= 0 && r < h && c >= 0 && c < w;
}

void xplore(int r, int c, int a, int b) {
    queue <pair<int, int> > Q;
    Q.push(make_pair(r, c));
    M[r][c] = '0';

    while (!Q.empty()) {
        pair <int, int> q = Q.front();
        Q.pop();

        for (int i = a; i < b; i++) {
            int nr = q.first + dr[i];
            int nc = q.second + dc[i];
            if (valid(nr, nc) && M[nr][nc] == '1') {
                M[nr][nc] = '0';
                Q.push(make_pair(nr, nc));
            }
        }
    }
}

void plusB(int r, int c) {
    xplore(r, c, 0, 4);
}

void crossB(int r, int c) {
    xplore(r, c, 4, 8);
}

void starB(int r, int c) {
    xplore(r, c, 0, 8);
}

int main() {
    cin >> t;

    while (t--) {
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            cin >> CM[i];
        }

        memcpy(M, CM, sizeof CM);
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (M[i][j] == '1') {
                    plusB(i, j);
                    ans++;
                }
            }
        }
        cout << ans << " " ;

        memcpy(M, CM, sizeof CM);
        ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (M[i][j] == '1') {
                    crossB(i, j);
                    ans++;
                }
            }
        }
        cout << ans << " " ;

        memcpy(M, CM, sizeof CM);
        ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (M[i][j] == '1') {
                    starB(i, j);
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

}