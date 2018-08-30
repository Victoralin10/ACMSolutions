#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

clock_t _inicio = clock();

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

const int MAXN = 1003;

char s[MAXN][MAXN];

int main(int nargs, char **args) {
    int n;
    while (scanf("%d", &n) == 1) {
        REP (i, n) scanf("%s", s[i]);
        int m = strlen(s[0]);
        int cnt;
        bool tb;

        cnt = 0;
        tb = 0;
        REP (j, m) {
            REP (i, n) {
                char c = s[i][j];
                if (c != '_') {
                    tb = 1;
                    break;
                }
                cnt++;
            }
            if (tb) break;
        }

        cnt = n * m - cnt;
        tb = 0;
        for (int j = m - 1; j >= 0; j--) {
            for (int i = n - 1; i >= 0; i--) {
                char c = s[i][j];
                if (c == '\\') {
                    putchar('\n');
                } else if (c == '_') putchar(' ');
                else putchar(c);
                cnt--;
                if (cnt == 0) {
                    tb = 1;
                    break;
                }
            }
            if (tb) break;
        }
        puts("");
        puts("");
    }
    
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
