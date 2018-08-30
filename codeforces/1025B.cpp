#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define CLR(t, value) memset(t, value, sizeof(t))
#define ALL(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;
#define sc(x) scanf("%d", &x)

using namespace std ;

typedef long long Long;
typedef vector<int> vInt;
typedef pair<int,int> Pair;

const int N = 1e5 + 5e4 + 5;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

int A[N], B[N];

vector <int> gp(int n) {
    vector <int> ans;
    for (int i = 2; i*i <= n; i++) {
        if (n%i == 0) {
            ans.push_back(i);
            while (n%i == 0) n /= i;
        }
    }
    if (n > 1) ans.push_back(n);
    return ans;
}

int main() {
    int n, a, b, a1, a2;
    cin >> n;
    REP(i, n) cin >> A[i] >> B[i];

    set <int> st;
    for (int p: gp(A[0])) st.insert(p);
    for (int p: gp(B[0])) st.insert(p);

    int ans = -1;
    for (int pp: st) {
        bool ok = 1;
        REP(i, n) {
            if (A[i]%pp != 0 && B[i]%pp != 0) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ans = pp;
            break;
        }
    }
    cout << ans << endl;

    return 0 ;
}
