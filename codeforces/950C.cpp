#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define CLR(t, value) memset(t, value, sizeof(t))
#define ALL(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;
#define sc(x) scanf("%d", &x)

using namespace std;

typedef long long Long;
typedef vector<int> vInt;
typedef pair<int,int> Pair;

const int N = 2e5 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

char s[N];

int main() {
    scanf("%s", s);
    int l = strlen(s);

    int cnt[2] = {0, 0};
    REP(i, l) cnt[s[i]-'0']++;
    int k = cnt[0] - cnt[1];

    if (k < 1) {
        puts("-1");
        return 0;
    }

    bool ok = 1;
    vector <vInt> ans;
    priority_queue <int> Q[2];
    REP(i, l) {
        if (s[i] == '0') {
            if (Q[1].empty() && SZ(ans) == k) {
                ok = 0;
                break;
            }
            if (Q[1].empty()) {
                ans.push_back(vector<int>(1, i));
                Q[0].push(-SZ(ans) + 1);
            } else {
                int q = Q[1].top(); Q[1].pop();
                ans[-q].push_back(i);
                Q[0].push(q);
            }
        } else {
            if (Q[0].empty()) {
                ok = 0;
                break;
            }
            int q = Q[0].top(); Q[0].pop();
            ans[-q].push_back(i);
            Q[1].push(q);
        }
    }

    if (!ok) {
        puts("-1");
    } else {
        cout << k << endl;
        REP(i, k) {
            printf("%d", SZ(ans[i]));
            REP(j, SZ(ans[i])) {
                printf(" %d", ans[i][j]+1);
            }
            puts("");
        }
    }


    return 0 ;
}
