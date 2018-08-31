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

const int N = 1e3 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

/************************************/

int P[N];
bool vis[N];

int main() {
    int n;
    cin>>n;
    REP(i,n)cin>>P[i], P[i]--;

    REP(i,n) {
        CLR(vis, 0);
        int ca=i;
        while (!vis[ca]) vis[ca]=1,ca=P[ca];
        cout<<ca+1<<" ";
    }

    return 0 ;
}
