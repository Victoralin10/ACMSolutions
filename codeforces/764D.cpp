#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define ll long long
#define ull long long
#define ld long double

#define MOD 1000000007
#define MAXN 10

using namespace std;

int n;
pair <pii, pii > recs;
map <int, set < pair <pii, int > > > X, Y;

vector <int> G[MAXN];



int main(int nargs, char **args) {
    cin >> n;

    set <pair < pii, int > >::iterator it;

    for (int i = 0, x0, y0, x1, y1; i < n; i++) {
        cin >> x0 >> y0 >> x1 >> y1;

        if (X.find(x0) != X.end()) {
            it = X[x0].lower_bound(mp(mp(y1, -1), -1));
            if (it != X[x0].end() && it->fi.se >= y1) {
                G[i].pb(it->se);
                G[it->se].pb(i);
            }
        }
        if (X.find(x1) != X.end()) {
            it = X[x1].lower_bound(mp(mp(y0, y1), -1));
            if (it != X[x1].end() && it->fi.se >= y1) {
                G[i].pb(it->se);
                G[it->se].pb(i);
            }
        }
        if (Y.find(y0) != Y.end()) {
            it = Y[y0].lower_bound(mp(mp(x0, x1), -1));
            if (it != Y[y0].end() && it->fi.se >= x1) {
                G[i].pb(it->se);
                G[it->se].pb(i);
            }
        }
        if (Y.find(y1) != Y.end()) {
            it = Y[y1].lower_bound(mp(mp(x0, x1), -1));
            if (it != Y[y1].end() && it->fi.se >= x1) {
                G[i].pb(it->se);
                G[it->se].pb(i);
            }
        }

        X[x0].insert(mp(mp(y1, i), y0));
        X[x1].insert(mp(mp(y1, i), y0));
        Y[y0].insert(mp(mp(x1, i), x0));
        Y[y1].insert(mp(mp(x1, i), x0));
    }

    for (int i = 0; i < n; i++) {
        cout << G[i].size() << endl;
    }

    return 0;
}
