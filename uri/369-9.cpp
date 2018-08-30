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

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;
const int MOD = 1e9 + 7 ;
const double EPS = 1e-8 ;

/************************************/

Pair gcd(int a, int b) {
    if (b == 0) return  {1, 0};

    Pair q = gcd(b, a%b);
    return {q.second, q.first - (a/b)*q.second};
}

int main() {
    int d, e;
    cin >> d >> e;
    if (__gcd(d, e) != 1) puts("IMPOSSIVEL");
    else {
        Pair q = gcd(d, e);
        cout << abs(q.first - q.second) << endl;
    }
    return 0 ;
}
