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

void solve(vector <vInt> &caso) {
    sort(all(caso));

    set <int> starts;
    for (vInt &t: caso) {
        starts.insert(t[0]);
    }

    Pair ans = {-1, -1};
    for (int a: starts) {
        int cnt = 0;
        for (vInt &t: caso) {
            if (a < t[0] || a > t[1]) continue;
            if ((a - t[0])%t[2] == 0) cnt++;
        }
        if ((cnt&1)) {
            ans = {a, cnt};
            break;
        }
    }

    if (ans.first > 0) cout << ans.first << " " << ans.second << endl;
    else puts("no corruption");
}

int main(int nargs, char **args) {
    string line;
    vector <vInt> caso;
    while (getline(cin, line)) {
        if (line == "") {
            if (SZ(caso) > 0) {
                solve(caso);
                caso.clear();
            }
        } else {
            stringstream io(line);
            int a, b, k;
            io >> a >> b >> k;
            caso.push_back({a, b, k});
        }
    }
    if (SZ(caso) > 0) {
        solve(caso);
    }
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
