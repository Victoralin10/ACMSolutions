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

/************************************/
int F[N];

int main() {
    int n;
    cin>>n;
    REP(i,n)cin>>F[i];
    REP(i,n) F[i]--;

    bool ok = 0;
    REP(i,n){
        int b=F[i],c=F[b],a=F[c];
        if (a==i && a!=b && b!=c && a!=c) ok = 1;
    }
    puts(ok?"YES":"NO");

    return 0 ;
}
