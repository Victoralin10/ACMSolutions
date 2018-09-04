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

int T[4*N], A[N], V[N];

void upd(int nd, int izq, int der) {
    T[nd]=T[izq]+T[der];
}

void init(int nd, int i, int j) {
    if (i == j) {
        T[nd]=A[i];
        return;
    }
    int mi=(i+j)>>1, izq=(nd<<1)+1, der=izq+1;
    init(izq,i,mi);
    init(der,mi+1,j);
    upd(nd,izq,der);
}

void update(int nd, int i, int j, int px) {
    if (px < i || px > j) return;

    if (i==j) {
        T[nd]=0;
        return;
    }

    int mi=(i+j)>>1, izq=(nd<<1)+1, der=izq+1;
    update(izq, i,mi, px);
    update(der,mi+1,j,px);
    upd(nd, izq,der);
}

int query(int nd, int i, int j, int px) {
    if (i==j) {
        return i;
    }
    int izq=(nd<<1)+1,der=izq+1,mi=(i+j)>>1;
    if (px < T[der]) return query(der, mi+1,j, px);
    return query(izq,i,mi,px-T[der]);
}

int main() {
    // fast_io();
    int t, n;
    sc(t);
    REP(j,t) {
        cin>>n;
        REP(i,n) sc(V[i]),A[i]=1;
        init(0, 0,n-1);

        bool ok=1;
        for(int i=n-1; i>=0; i--) {
            if (V[i]>i) {
                ok=0;
                break;
            }
            V[i]=query(0,0,n-1,V[i]);
            update(0,0,n-1,V[i]);
            V[i]++;
        }

        printf("Test : %d\n", j+1);
        if (!ok) printf("-1\n");
        else {
            REP(i,n) printf("%d%c",V[i],i+1==n?'\n':' ');
        }
    }
    return 0 ;
}
