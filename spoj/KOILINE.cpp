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
typedef struct Nd * pnd;
struct Nd {
    int key, cnt, pri;
    pnd l, r;
    Nd(int key, int pri):key(key),cnt(1),pri(pri),l(NULL),r(NULL){}
};

inline int cnt(pnd t) { return t?t->cnt:0; }
inline void upd_cnt(pnd t) { if(t) t->cnt=1+cnt(t->l)+cnt(t->r); }

void merge(pnd &t, pnd l, pnd r) {
    if (!l || !r) t=(l?l:r);
    else if (l->pri > r->pri) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l), t=r;
    upd_cnt(t);
}

void split(pnd t, int key, pnd &l, pnd &r) {
    if (!t) l=r=NULL;
    else if (t->key < key) split(t->r, key, t->r, r), l=t;
    else split(t->l, key, l, t->l), r=t;
    upd_cnt(l), upd_cnt(r);
}

void insert(pnd &t, pnd nnd) {
    if (!t) t=nnd;
    else if (nnd->pri > t->pri) split(t, nnd->key, nnd->l, nnd->r), t=nnd;
    else insert(t->key < nnd->key?t->r:t->l, nnd);
    upd_cnt(t);
}

int erase(pnd &t, int ind) {
    if (!t) return -1;
    int ans=0;
    if (ind < cnt(t->l)) ans = erase(t->l, ind);
    else if (ind > cnt(t->l)) ans = erase(t->r, ind - 1 - cnt(t->l));
    else {
        ans=t->key;
        merge(t, t->l, t->r);
    }
    upd_cnt(t);
    return ans;
}

void print(pnd t, bool end=true) {
    if (t) {
        print(t->l, false);
        cout<<"{"<<t->key<<"}";
        print(t->r, false);
    }
    if (end) cout<<endl;
}

int A[N];

int main() {
    fast_io();
    int n, h;
    cin>>n;
    pnd root=NULL;
    REP(i, n) {
        cin>>h;
        insert(root, new Nd(h, random()));
    }
    REP(i, n) cin>>A[i];
    // print(root);
    for (int i=n-1;i>=0;i--) A[i]=erase(root, A[i]);
    REP(i,n) cout<<A[i]<<endl;
    return 0 ;
}
