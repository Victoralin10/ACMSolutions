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

const int N = 5e5 + 2;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const double EPS = 1e-8;

void fast_io() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

/************************************/

int A[N], r, nb;
vector <int> V[1000];

void update(int i, int nn) {
  int old=A[i];
  int b=i/r;
  int ind=lower_bound(ALL(V[b]), old)-V[b].begin();
  V[b][ind]=nn;
  while(ind<r-1 && V[b][ind]>V[b][ind+1]) swap(V[b][ind],V[b][ind+1]), ind++;
  while(ind>0 && V[b][ind]<V[b][ind-1]) swap(V[b][ind], V[b][ind-1]), ind--;
  A[i]=nn;
}

int query(int a, int b, int c) {
  int ba=a/r,bb=b/r;
  int ans=0;
  if (ba==bb) {
    FOR(i,a,b+1) ans += A[i]>=c;
    return ans;
  }
  int l=(ba+1)*r;
  FOR(i,a,l) ans+=A[i]>=c;
  FOR(i,bb*r,b+1)ans+=A[i]>=c;
  FOR(i,ba+1,bb){
    ans += V[i].end()-lower_bound(ALL(V[i]), c);
  }
  return ans;
}

int main() {
  // fast_io();
  int n, q, t, a, b, c;
  sc(n);
  REP(i,n)sc(A[i]);
  r=sqrt(n+0.5);
  nb=(n+r-1)/r;
  REP(i,n)V[i/r].push_back(A[i]);
  REP(i,nb)sort(ALL(V[i]));
  
  sc(q);
  while(q--){
    sc(t);
    if(t==0) {
      scanf("%d%d%d", &a, &b, &c);
      printf("%d\n", query(a-1,b-1,c));
    } else {
      scanf("%d%d", &a, &b);
      update(a-1, b);
    }
  }
  return 0 ;
}
