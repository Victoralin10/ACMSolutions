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

const int N = 3e3 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

int p[N], c[N], cnt1=0;
Pair cc[N];
map<int, set<Pair>> mp;
bool vis[N];
int n, m;

Long solve(int nv) {
    if (nv < cnt1) return 1e18;
    int nc=nv-cnt1;

    Long ans=0;
    CLR(vis, 0);
    for (auto &x: mp) {
        if (SZ(x.second)>=nv) {
            int cnt=SZ(x.second)-nv+1;
            auto it=x.second.begin(), ite=x.second.end();
            while (it!=ite && nc>0 && cnt>0) {
                ans += it->first;
                vis[it->second]=1;
                cnt--, nc--, it++;
            }
            if (cnt>0) return 1e18;
        }
    }
    REP(i, n) {
        if (!nc) break;
        if (!vis[cc[i].second]) ans += cc[i].first, nc -= cc[i].first>0;
    }
    return ans;
}

int main() {
    cin>>n>>m;
    REP(i,n) cin>>p[i]>>c[i];

    REP(i, n) {
        if (p[i]!=1) mp[p[i]].insert({c[i], i});
        else cnt1++;
        cc[i] = {p[i]>1?c[i]:0, i};
    }
    sort(cc, cc+n);

    Long ans=1e18;
    FOR(i,1,n+1) ans = min(ans, solve(i));
    cout<<ans<<endl;

    return 0 ;
}
