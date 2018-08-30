#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

char S[5][10];
int SUM[6], F[6], M[5][10];
vector <int> P[5][10];
int R = 5, C = 9;
bool used[30];

void scan(int r, int c, int dr, int dc, int id) {
    REP(i, 4) {
        if (S[r][c] == 'x') {
            M[r][c] = -1;
        } else {
            M[r][c] = 1 + (S[r][c] - 'A');
            F[id]++;
            SUM[id] += M[r][c];
            used[M[r][c]] = 1;
        }
        P[r][c].push_back(id);
        r += dr, c += dc;
    }
}

bool ans = false;

void back(int r, int c) {
    if (r == R) {
        ans = true;
        REP(i, 6) {
            if (SUM[i] != 26) {
                ans = false;
                break;
            }
        }
        return;
    }
    if (c == C) {
        back(r + 1, 0);
        return;
    }
    if (M[r][c] != -1) {
        back(r, c + 1);
        return;
    }

    REPR(i, 1, 13) {
        if (ans) break;
        if (used[i]) continue;

        M[r][c] = i;
        used[i] = 1;
        bool ok = true;
        for (auto si: P[r][c]) {
            SUM[si] += i;
            F[si]++;
            if (SUM[si] > 26 || (F[si] == 4 && SUM[si] != 26)) ok = false;
        }
        if (ok) {
            back(r, c + 1);
        }
        if (ans) break;

        M[r][c] = -1;
        used[i] = 0;
        for (auto si: P[r][c]) {
            SUM[si] -= i;
            F[si]--;
        }
    }
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    REP(i, R) {
        cin >> S[i];
    }

    scan(1, 1, 1, 1, 0);
    scan(1, 1, 0, 2, 1);
    scan(1, 7, 1, -1, 2);
    scan(0, 4, 1, 1, 3);
    scan(0, 4, 1, -1, 4);
    scan(3, 1, 0, 2, 5);

    back(0, 0);
    assert(ans);

    REP(i, R) {
        REP(j, C) {
            if (M[i][j] > 0) {
                S[i][j] = char('A' + M[i][j] - 1);
            }
        }
    }

    REP(i, R) {
        cout << S[i] << endl;
    }

    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
