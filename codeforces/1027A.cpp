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


int main(int nargs, char **args) {
    int t, n;
    cin >> t;
    while (t--) {
        string s;
        cin >> n >> s;

        bool ok = 1;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            int d = abs((int)s[i] - (int)s[j]);
            if (d != 0 && d != 2) ok = 0;
        }
        puts(ok?"YES":"NO");
    }
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
