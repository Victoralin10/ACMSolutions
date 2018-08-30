/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 11
#define MAXS 37

#define S second
#define F first
#define pb push_back
#define mp make_pair
#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define pii pair<int, int>
#define FN(i, n) for(int (i) = 0; (i) < (n) ; (i)++)
#define FOR(i, ini, n) for(int (i) = (ini); (i) < (n) ; (i)++)
#define me(a, v) memset(a, v, sizeof(a))
#define SZ(x) ((int)x.size())
using namespace std;



string vals[MAXN];
char st[7]; // state
int n, m;
bool vis[MAXS][MAXN][MAXN];
int dist[MAXS][MAXN][MAXN];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int rotv[] = {2, 4, 3, 5};
int roth[] = {4, 0, 5, 1};

void tr(int mod, char st[7], char nst[7]) {
	FN (i, 6) {
		nst[i] = st[i];
	}
	if (mod == 0) {
		FN (i, 4) {
			nst[rotv[i]] = st[rotv[(i + 3)%4]];
		}
	} else if (mod == 1) {
		FN (i, 4) {
			nst[rotv[i]] = st[rotv[(i + 1)%4]];
		}
	} else if (mod == 2) {
		FN (i, 4) {
			nst[roth[i]] = st[roth[(i + 3)%4]];
		}
	} else if (mod == 3) {
		FN (i, 4) {
			nst[roth[i]] = st[roth[(i + 1)%4]];
		}
	}
}

int getId(char sta[7]) {
	return (sta[0] - '1')*6 + (sta[1] - '1');
}

int main(int nargs, char **args) {
	int tc;
	sc(tc);
	FN (itc, tc) {
		cin >> st;
		sc2(n, m);
		int sx , sy ;
		FN (i, n) {
			cin >> vals[i];
			FN (j, m) {
				if (vals[i][j] == 'S') {
					sx = i;
					sy = j;
				}
			}
		}

		priority_queue<pair<pair<char[7], pair<int, int> >, int> > pq;
		pq.push(mp(st, mp(sx, sy)));

		me(vis, 0);
		dist[getId(st)][sx][sy] = 0;
		while (!pq.empty()) {
			pair<char[7], pair<int, int> > nn = pq.top();
			pq.pop();
			vis[getId(nn.F)][nn.S.F][nn.S.S] = 1;

			if (vals[nn.S.F][nn.S.S] == 'T') continue;

			FN (move, 4) {
				int sx = nn.S.F + dx[move];
				int sy = nn.S.S + dy[move];

				char sst[7];
				tr(move, nn.F, sst);
				if (sx >= 0 && sx < n && sy >= 0 && sy < m) {
					if (vals[sx][sy] != '.' && vals[sx][sy] != 'S') {
						int add = (sst[5] - '0') + vals[sx][sy] - '0';
						if ((sst[5] - '0') != vals[sx][sy] - '0') add *= -1;
						pq.push(mp(sst,mp(sx,sy)));
					}
				}
			}
		}
	}
}
