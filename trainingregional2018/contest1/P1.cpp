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
        cin >> n;
        int x, xo = 0, cnt = 0;
        REP(i, n) {
            cin >> x;
            cnt += (x==1);
            xo ^= x;
        }

        bool ok = (cnt == n && n%2 == 0) || (cnt < n && xo > 0);
        puts(ok?"John":"Brother");
    }
    
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
