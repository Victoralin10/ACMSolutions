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

const int N = 1e5 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

/************************************/

typedef long double Double;

int main() {
    // fast_io();
    int t;
    sc(t);
    REP(caso,t){
        Double n, r, p, ans;
        scanf("%Lf%Lf%Lf", &n, &r, &p);
        //cin>>n>>r>>p;
        if (n >= p) ans = 0;
        else ans = ceil(log10(p/n)/log10(1 + r/100.0));
        printf("Case %d: %d\n", caso+1, (int)ans);
    }
    return 0 ;
}
