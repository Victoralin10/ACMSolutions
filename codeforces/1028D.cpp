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

int main() {
    int n;
    uint p;
    char ord[10];
    cin >> n;

    long long ans = 1;
    vector <pair <bool, uint> > A; 
    REP(i, n) {
        scanf("%s%d", ord, &p);
        A.push_back({ord[1]=='D', p});
    }
    reverse(ALL(A));


    cout << ans << endl;

    
    return 0;
}
