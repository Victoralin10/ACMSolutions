/**
* Title:            B. Lucky Common Subsequence
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 101

using namespace std;

char a[MAXN], b[MAXN], c[MAXN];
int K[MAXN], la, lb, lc;
int memo[MAXN][MAXN][MAXN];
int back[MAXN][MAXN][MAXN];

int dp(int i, int j, int k) {
    int &ans = memo[i][j][k];
    int pa;
    if (ans != -1) return ans;
    ans = 0;

    if (i < la) {
        ans = dp (i + 1, j, k);
        back[i][j][k] = -1;
    }

    if (j < lb) {
        pa = dp (i, j + 1, k);
        if (pa > ans) {
            ans = pa;
            back[i][j][k] = -2;
        }
    }

    if (a[i] == b[j] && i < la && j < lb) {
        int nk = k;
        while (nk != -1 && a[i] != c[nk]) nk = K[nk];
        nk++;

        if (nk < lc) {
            pa = 1 + dp(i + 1, j + 1, nk);
            if (pa > ans) {
                ans = pa;
                back[i][j][k] = nk;
            }
        }
    }

    return ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    memset(memo, -1, sizeof memo);

    cin >> a >> b >> c;

    la = strlen(a);
    lb = strlen(b);
    lc = strlen(c);

    K[0] = -1; K[1] = -1;
    for (int i = 0, j = -1; i < lc; ) {
        while (j != -1 && c[i] != c[j]) j = K[j];
        K[++i] = ++j;
    }

    int ml = dp(0, 0, 0);
    if (ml == 0) cout << "0" << endl;
    else {
        string ans = "";
        int i = 0, j = 0, k = 0;
        while (i < la && j < lb) {
            int b = back[i][j][k];
            if (b == -1) i++;
            else if(b == -2) j++;
            else {
                ans += a[i];
                i++;
                j++;
                k = b;
            }
        }
        cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
