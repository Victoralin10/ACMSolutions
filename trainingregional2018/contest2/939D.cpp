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
int H[250];

int F(int x) { return x==H[x]?x:H[x]=F(H[x]); }
void U(int x, int y) { H[F(x)]=F(y); }

int main() {
    REP(i, 200) H[i]=i;

    int n;
    string a,b;
    cin>>n>>a>>b;

    vector<pair<char,char> > v;
    REP(i,n) {
        if (F(a[i])!=F(b[i])) {
            U(a[i],b[i]);
            v.push_back({a[i], b[i]});
        }
    }
    cout<<SZ(v)<<endl;
    REP(i,SZ(v)) cout <<v[i].first<<" "<<v[i].second<<endl;

    return 0 ;
}
