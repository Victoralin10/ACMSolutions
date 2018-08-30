#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

typedef long long Long;
typedef vector<int> vInt;
typedef vector<vInt> vvInt;
typedef vector<string> vStr;
typedef pair<int, int> Pair;
typedef vector<pair<int, int> > vPair;

map<int, int> f;

int main(int nargs, char **args) {
    //clock_t _inicio = clock();
    int n, x;
    cin >> n >> x;
    Long ans = 0;
    REP (i, n) {
        int v;
        cin >> v;

        int q = v^x;
        if (f.find(q) != f.end()) ans += f[q];
        f[v]++;
    }
    cout << ans;
    //fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
