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

typedef struct Nd * pnd;

struct Nd {
    int cnt, pri;
    Pair key;
    pnd l, r;
    Nd(Pair key) {
        this->key=key;
        pri = rand();
        l=r=NULL;
    }
};

inline int cnt(pnd &t) { return t?t->cnt:0; }
inline void upd_cnt(pnd &t) { if (t) t->cnt = 1+cnt(t->l)+cnt(t->r); }

// split, merge, insert, erase

void merge(pnd &t, pnd l, pnd r) {
    if (!l || !r) t = l?l:r;
    else if (l->pri > r->pri) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l), t=r;
    upd_cnt(t);
}

void split(pnd t, Pair &key, pnd &l, pnd &r) {
    if (!t) l=r=NULL;
    else if (t->key < key) split(t->r, key, t->r, r), l=t;
    else split(t->l, key, l, t->l), r=t;
    upd_cnt(l), upd_cnt(r);
}

void insert(pnd &t, pnd &nnd) {
    if (!t) t=nnd;
    else if (nnd->pri > t-> pri) split(t, nnd->key, nnd->l, nnd->r), t=nnd;
    else insert(nnd->key<t->key?t->l:t->r, nnd);
    upd_cnt(t);
}

void print(const Pair &a) {
    printf("{%d,%d}", a.first, a.second);
}

void erase(pnd &t, const Pair &key) {
    assert(t != NULL);
    if (t->key==key) merge(t, t->l, t->r);
    else erase(key<t->key?t->l:t->r, key);
    upd_cnt(t);
}

int query(pnd &t, const Pair &key) {
    if (!t) return 0;
    if (t->key < key) return 1 + cnt(t->l) + query(t->r, key);
    return query(t->l, key);
}


void print(pnd &t) {
    if (!t) return;
    print(t->l);
    print(t->key);
    print(t->r);
}

int C[N];

int main() {
    fast_io();

    pnd t=NULL;
    int n,q,c, a, b;
    cin>>n>>q;
    REP(i, n) {
        cin>>c;
        pnd nd = new Nd({c, i});
        insert(t, nd);
        C[i]=c;
    }
    //print(t);puts("");
    while (q--) {
        cin>>a>>b;
        cout << query(t, {b, a}) - query(t, {b, -1}) << endl;
        erase(t, {C[a], a});
        pnd nd = new Nd({b, a});
        insert(t, nd);
        C[a]=b;
        //print(t), puts("");
    }

    return 0 ;
}
