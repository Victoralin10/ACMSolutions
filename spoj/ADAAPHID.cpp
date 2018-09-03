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
    int pri;
    Long key, val, sum;
    pnd l, r;
    Nd(Long key, Long val) {
        this->key = key;
        pri = random();
        this->val=sum=val;
        l=r=NULL;
    }
};

inline Long sum(pnd &t) { return t?t->sum:0; }
inline void upd_sum(pnd &t) { if(t) t->sum=t->val+sum(t->l)+sum(t->r); }

void merge(pnd &t, pnd &l, pnd &r) {
    if (!l || !r) t=l?l:r;
    else if (l->pri > r->pri) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l), t=r;
    upd_sum(t);
}

void split(pnd t, Long &key, pnd &l, pnd &r) {
    if (!t) l=r=NULL;
    else if (t->key < key) split(t->r, key, t->r, r),l=t;
    else split(t->l, key, l, t->l), r=t;
    upd_sum(l), upd_sum(r);
}

bool update(pnd &t, Long &key, Long val) {
    if (!t) return false;
    if (t->key==key) {
        t->val += val;
        upd_sum(t);
        return true;
    }
    if (update(key<t->key?t->l:t->r, key, val)) {
        upd_sum(t);
        return true;
    }
    return false;
}

void insert(pnd &t, pnd &nnd) {
    if (!t) t=nnd;
    else if (nnd->pri > t->pri) split(t, nnd->key, nnd->l, nnd->r), t=nnd;
    else insert(nnd->key < t->key?t->l:t->r, nnd);
    upd_sum(t);
}

Long query(pnd &t, Long &key) {
    if (!t) return 0;
    if (t->key > key) return query(t->l, key);
    return sum(t->l)+t->val+query(t->r, key);
}

int main() {
    fast_io();
    int q;
    Long a, l=0, v;
    cin>>q;
    pnd t=NULL;
    while(q--) {
        cin>>a>>v;
        a^=l, v^=l;
        cerr<<a<<" "<<v<<endl;
        if (!update(t, a, v)) {
            pnd nd = new Nd(a, v);
            insert(t, nd);
        }
        l=query(t, a);
        cout<<a<<" "<<l<<endl;
    }
    return 0 ;
}
