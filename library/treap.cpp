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
// https://cp-algorithms.com/data_structures/treap.html

typedef int tnd;
typedef struct Nd * pnd;

struct Nd {
  tnd key;
  int pri;
  pnd l, r;
  Nd() {}
  Nd(tnd key, int pri):key(key), pri(pri), l(NULL), r(NULL) {}
};

void split(pnd t, tnd key, pnd &l, pnd &r) {
  if (!t) l=r=NULL;
  else if (key<t->key) split(t->l, key, l, t->l), r=t;
  else split(t->r, key, t->r, r), l=t;
}

void insert(pnd &t, pnd nnd) {
  if (!t) t=nnd;
  else if (nnd->pri > t->pri) split(t, nnd->key, t->l, t->r), t=nnd;
  else insert(nnd->key < t->key?t->l:t->r, nnd);
}

void merge(pnd &t, pnd l, pnd r) {
  if (!l) t=r;
  else if (!r) t = l;
  else if (l->pri>r->pri) merge(l->r, l->r, r), t=l;
  else merge(r->l, l, r->l), t=r;
}

void erase(pnd &t, tnd key) {
  if (!t) return;
  else if (t->key==key) merge(t, t->l, t->r);
  else erase(key<t->key?t->l:t->r, key);
}

void to_vector(pnd &t, vector<tnd> &a) {
  if (!t) return;
  to_vector(t->l, a);
  a.push_back(t->key);
  to_vector(t->r, a);
}

int main() {
  pnd mtreap=NULL;
  int n, x;
  cin>>n;
  REP(i, n) {
    cin>>x;
    pnd mnd = new Nd(x, random());
    insert(mtreap, mnd);
  }
  vector<tnd> a;
  to_vector(mtreap, a);
  REP(i, n) cout<<a[i]<<" ";
  cout << endl;
}