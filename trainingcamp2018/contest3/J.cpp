#include<bits/stdc++.h>

using namespace std ;

const int N = 1e5 + 2 ;
const int INF = 1e9 + 7 ;

/*********************************/
pair <int, int> P[500];

int dp[303][303], E[303][303], invmap[303];

int query(int x1, int y1, int x2, int y2) {
	return dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
}

int main() {
	int t, n;
	
	cin >> t;
	while (t--) {
		cin >> n;
		set <int> setx, sety;

		for (int i = 0, x, y; i < n; i++) {
			cin >> x >> y;
			setx.insert(x);
			sety.insert(y);

			P[i] = {x, y};
		}
		sort(P, P + n);

		map <int, int> mapx, mapy;
		int idx = 0;
		for (auto x: setx) {
			mapx[x] = ++idx;
		}
		int idy = 0;
		for (auto x: sety) {
			mapy[x] = ++idy;
			invmap[idy] = x;
		}
		memset(E, 0, sizeof E);
		
		for (int i = 0; i < n; i++) {
			E[mapx[P[i].first]][mapy[P[i].second]] += 1;
		}

		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= idx; i++) {
			for (int j = 1; j <= idy; j++) {
				dp[i][j] = E[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}

		int ans = (n>1?(1<<30):0);
		for (int i = 0; i < n && ans; i++) {
			for (int j = i + 1; j < n && ans; j++) {
				int x1 = min(P[i].first, P[j].first),
					x2 = max(P[i].first, P[j].first);
				int mx1 = mapx[x1], mx2 = mapx[x2];
				int y1 = 1, y2 = 1;
				while (y1 <= idy && y2 <= idy) {
					while (y2 <= idy && query(mx1, y1, mx2, y2) <= n/2) {
						y2++;
					}
					if (y2 <= idy && query(mx1, y1, mx2, y2) > n/2) {
						ans = min(ans, (x2 - x1)*(invmap[y2] - invmap[y1]));
					}
					y1++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0 ;
}