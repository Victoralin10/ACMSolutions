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
int A[N];

int main() {
    // fast_io();
    int t, n, k;
    cin>>t;
    REP(caso, t) {
        cin>>n>>k;
        REP(i,n) cin>>A[i];
        sort(A, A + n);
        // reverse(A, A + n);

        set <int> st;
        int base=0; Long ans=0;
        REP(i,k-1) st.insert(A[i]);
        FOR(i,k-1,n) {
            st.insert(A[i] + base);
            auto it=st.begin();
            // TEST(*it)
            ans += (*it) - base;
            base = *it;
            st.erase(it);
        }
        cout << "Case " <<caso+1<< ": " << ans <<endl;
    }
    return 0 ;
}
