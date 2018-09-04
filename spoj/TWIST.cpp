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
    int cnt, pri, val;
    pnd l, r;
    bool rev;
    Nd(int val, int pri):cnt(1),pri(pri),val(val),l(NULL),r(NULL),rev(false){}
};


inline int cnt(pnd t) { return t?t->cnt:0; }
inline void upd_cnt(pnd t) { if (t)t->cnt=1+cnt(t->l)+cnt(t->r); }

inline void rev(pnd t) {
    if (t) {
        t->rev = !t->rev;
    }
}

inline void push(pnd t) {
    if (t && t->rev) {
        t->rev=false;
        rev(t->l), rev(t->r);
        swap(t->l, t->r);
    }
}

void print(pnd t, bool end=true) {
    if (t) {
        push(t);
        print(t->l, false);
        if (t->l)cout<<" ";
        cout<<t->val;
        if(t->r)cout<<" ";
        print(t->r, false);
    }
    if (end) cout << endl;
}

void merge(pnd &t, pnd l, pnd r) {
    if (!l || !r) return void(t=l?l:r);
    push(l), push(r);
    if (l->pri > r->pri) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l), t=r;
    upd_cnt(t);
}

void split(pnd t, int i, pnd &l, pnd &r) {
    if (!t) return void(l=r=NULL);
    push(t);
    if (cnt(t->l) < i) split(t->r,i - cnt(t->l) -1, t->r, r),l=t;
    else split(t->l, i, l, t->l), r=t;
    upd_cnt(l), upd_cnt(r);
}

void rev(pnd &t, int i, int j) {
    pnd a, b, c;
    split(t, j+1, b, c);
    split(b, i, a, b);
    rev(b);
    merge(t, a, b);
    merge(t, t, c);
}

int main() {
    fast_io();
    int n, q, i, j;
    cin>>n>>q;
    pnd t=NULL;
    REP(i, n) {
        pnd nd = new Nd(i+1, random());
        merge(t, t, nd);
    }
    while (q--) {
        cin>>i>>j;
        i--, j--;
        rev(t, i, j);
    }
    print(t);

    return 0 ;
}
