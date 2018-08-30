/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 26*26*26

#define pb push_back
#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define pii pair<int, int>
#define FN(i, n) for(int (i) = 0; (i) < (n) ; (i)++)
#define FOR(i, ini, n) for(int (i) = (ini); (i) < (n) ; (i)++)
#define me(a, v) memset(a, v, sizeof(a))
#define SZ(x) ((int)x.size())
using namespace std;

int n, e;

vector<int> adj[MAXN];
vector<int> rev[MAXN];
set<int> bef[MAXN];
int memo[MAXN];
int dist[MAXN];



int encode(string &s) {
	int ini = 0;
	FN (i, 3) {
		ini *= 26;
		ini += s[i] - 'A';
	}
	return ini;
}

void bfs(int s, int t) {
	me(dist, -1);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int nn = q.front();q.pop();
		if (nn == t) break;
		FN (i, SZ(adj[nn])) {
			int son = adj[nn][i];
			if (dist[son] == -1) {
				dist[son] = dist[nn] + 1;
				q.push(son);
				rev[son].clear();
				rev[son].pb(nn);
			} else if (dist[son] == dist[nn] + 1) {
				rev[son].pb(nn);
			}
		}
	}
}

int dp(int x, int so) {
	if (x == so) return 0;
	int &mini = memo[x];
	if (mini != -1) {
		return mini;
	}
	mini = INT_MAX;
	FN(i, SZ(rev[x])) {
		int son = rev[x][i];
		mini = min(mini, (bef[x].find(son) == bef[x].end()) + dp(son, so));
	}

	//cout << x << " " << mini << endl;

	return mini;
}

int main() {
	int tc;
	sc(tc);
	FN (itc, tc) {
		FN (i, MAXN) {
			adj[i].clear();
			rev[i].clear();
			bef[i].clear();
		}
		me(memo, -1);
		sc(e);
		FN (i, e) {
			string a1, a2;
			cin >> a1 >> a2;
			int c1 = encode(a1), c2 = encode(a2);
//			cout << c1 << " " << c2 << endl;
			adj[c1].pb(c2);
			adj[c2].pb(c1);
		}
		int r;
		sc(r);
		int last = -1;
		int so, ta;
		FN (i, r + 1)  {
			string x;
			cin >> x;
			int cx = encode(x);
			if (last != -1) {
				bef[cx].insert(last);
			}
			if (i == 0) {
				so = cx;
			}
			if (i == r) ta = cx;
			last = cx;
		}
		bfs(so, ta);
		//int ans = 0;
		int ans = dp(ta, so);
		printf("%d\n", ans);
	}
}
