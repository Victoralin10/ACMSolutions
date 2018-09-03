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
    int key, pri, cnt;
    pnd l, r;
    Nd(int key, int pri):key(key),pri(pri),cnt(1),l(NULL),r(NULL){}
};

inline int cnt(pnd &t) { return t?t->cnt:0; }
inline void upd_cnt(pnd &t) { if (t) t->cnt=1+cnt(t->l)+cnt(t->r); }

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

void insert(pnd &t, pnd nnd) {
    if (!t) t=nnd;
    else if (nnd->pri > t->pri) split(t, nnd->key, nnd->l, nnd->r), t=nnd;
    else insert(nnd->key < t->key?t->l:t->r, nnd);
    upd_cnt(t);
}

void erase(pnd &t, int key) {
    if (!t) return;
    if (t->key == key) merge(t, t->l, t->r);
    else erase(key < t->key?t->l:t->r, key);
    upd_cnt(t);
}

int get(pnd t, int key) {
    if (!t) return -1;
    if (t->key == key) return cnt(t->l)+1;
    int ans;
    if (key < t->key) ans=get(t->l, key);
    else {
        ans=get(t->r, key);
        if (ans > 0) ans += cnt(t->l) + 1;
    }
    return ans;
}

int kth(pnd t, int k) {
    if (!t) return -1;
    if (cnt(t->l) >= k) return kth(t->l, k);
    if (k > 1+cnt(t->l)) return kth(t->r, k-1-cnt(t->l));
    return t->key;
}

int main() {
    // fast_io();
    srand(time(NULL));

    int t, y;
    pnd root=NULL;
    while (sc(t)) {
        if (t < 0) break;
        sc(y);
        if (t==1) insert(root, new Nd(y, random()));
        else if (t==2) erase(root, y);
        else if(t==3) printf("%d\n", get(root, y));
        else printf("%d\n", kth(root, y));
    }

    return 0 ;
}
