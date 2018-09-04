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

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

/************************************/

Long A[N];

Long solve(int i, int j) {
    if (i==j) {
        return A[i]>=0;
    }
    Long ans=0;

    int mid=(i+j)>>1;
    vector<Long> vac;
    Long ac=0;
    FOR(k,mid+1,j+1) {
        ac += A[k];
        vac.push_back(ac);
    }
    sort(ALL(vac));
    ac=0;
    for (int k=mid;k>=i;k--) {
        ac += A[k];
        auto it = lower_bound(ALL(vac), -ac);
        ans += vac.end() - it;
    }

    return ans+solve(i,mid)+solve(mid+1,j);
}

int main() {
    fast_io();
    int n;
    Long k, x;
    cin>>n>>k;
    REP(i,n) {
        cin>>x;
        A[i]=x-k;
    }
    cout<<solve(0, n-1)<<endl;

    return 0 ;
}
