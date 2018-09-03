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
    int key, freq, cnt, pri;
    pnd l, r;
    Nd(int key, int pri):key(key),pri(pri),freq(1),cnt(0),l(NULL),r(NULL){}
};

inline int cnt(pnd &t) { return t?t->cnt:0; }
inline void upd_cnt(pnd &t) {
    if (t) t->cnt=t->freq+cnt(t->l)+cnt(t->r);
}

void merge(pnd &t, pnd l, pnd r) {
    if (!l || !r) t=l?l:r;
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

bool add(pnd t, int key, int val) {
    if (!t) return false;

    bool ans;
    if (t->key == key) {
        t->freq += val;
        ans=true;
    } else if (t->key < key) ans=add(t->r, key, val);
    else ans=add(t->l, key, val);
    if (ans) upd_cnt(t);
    return ans;
}

void insert(pnd &t, pnd nnd) {
    if (!t) t=nnd;
    else if (nnd->pri > t->pri) split(t, nnd->key, nnd->l, nnd->r), t=nnd;
    else insert(nnd->key < t->key?t->l:t->r, nnd);
    upd_cnt(t);
}

int query(pnd t, int key) {
    if (!t) return 0;
    if (key < t->key) return query(t->l, key);
    return cnt(t->l)+t->freq+query(t->r, key);
}

int kth(pnd t, int k) {
    if (!t) return -1;
    if (cnt(t->l) >= k) return kth(t->l, k);
    if (k > cnt(t->l) + t->freq) return kth(t->r, k - cnt(t->l) - t->freq);
    return t->key;
}

int main() {
    fast_io();
    int n, q, x, y;
    cin>>n>>q;
    pnd t=NULL;
    REP(i, n) {
        cin>>y;
        if (!add(t, y, 1)) {
            pnd nd = new Nd(y, random());
            insert(t, nd);
        }
    }
    while(q--) {
        cin>>x>>y;
        if (x==1) {
            x=query(t, y);
            if (!add(t, x+y, 1)) {
                insert(t, new Nd(x+y, random()));
            } 
            n++;
        } else if(x==2) {
            x=query(t, y);
            cout<<x<<endl;
        } else {
            if (y>n) cout<<"invalid"<<endl;
            else cout<<kth(t, y)<<endl;
        }
    }

    return 0 ;
}
