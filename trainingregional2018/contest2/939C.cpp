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

int A[N];

int main() {
    int n, s, f, d;
    cin>>n;
    REP(i,n)cin>>A[i];
    REP(i,n)A[i+n]=A[i];
    cin>>s>>f;
    d=f-s;

    int ac=0,ans=-1,j=0,h=n+1;
    REP(i,n) {
        while (j-i<d) ac += A[j++];
        if (ac>ans) {
            ans=ac;
            h=(s-i+n)%n;
        } else if(ac==ans) {
            h=min(h,(s-i+n)%n);
        }
        ac -= A[i];
    }
    if (h==0)h=n;
    cout<<h<<endl;

    return 0 ;
}
