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
    vector < pair <int, int> > v;
    int n;
    cin >> n;
    REP(i, n) {
        int s = 0, x;
        REP(j, 4) {
            cin >> x;
            s += x;
        }
        v.push_back({-s, i});
    }
    sort(all(v));

    int ans = 0;
    REP(i, n) {
        if (v[i].second == 0) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;

    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
