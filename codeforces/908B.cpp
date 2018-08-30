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
#define MAXN 51

using namespace std;

int n, m, lseq;
char M[MAXN][MAXN], seq[2*MAXN];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};
int v[] = {0, 1, 2, 3};
int sr, sc, er, ec;

bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool ok() {
    int cr = sr, cc = sc;
    for (int i = 0; i < lseq; i++) {
        int nm = seq[i] - '0';
        cr += dr[v[nm]];
        cc += dc[v[nm]];

        if (!isValid(cr, cc) || M[cr][cc] == '#') return false;
        if (M[cr][cc] == 'E') return true;
    }
    return false;
}

int main(int nargs, char **args) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> M[i];
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 'S') {
                sr = i, sc = j;
            }
            if (M[i][j] == 'E') {
                er = i, ec = j;
            }
        }
    }
    cin >> seq;
    lseq = strlen(seq);

    int ans = 0;
    do {
        ans += ok();
    } while (next_permutation(v, v + 4));

    cout << ans << endl;

    return 0;
}
