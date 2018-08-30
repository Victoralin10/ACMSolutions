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
#define MAXN 100005

using namespace std;

vector <int > G[MAXN];
int parent[MAXN];
bool val[MAXN];

bool dfs(int cn, bool andOp) {
    if (G[cn].size() == 0) return val[cn];

    bool ans = andOp;
    if (andOp) {
        for (int i = 0; i < G[cn].size(); i++) {
            ans = ans && dfs(G[cn][i], 0);    
        }
    } else {
        for (int i = 0; i < G[cn].size(); i++) {
            ans = ans || dfs(G[cn][i], 1);
        }
    }

    return ans;
}

int main(int nargs, char **args) {
    string line;
    parent[0] = -1;
    int caso = 1;
    while (cin >> line) {
        if (line == "()") break;
        int cn = 0, nn = 1, h = 0, mh=-1;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '(') {
                G[cn].pb(nn);
                G[nn].clear();
                parent[nn] = cn;
                cn = nn;
                nn++;
                h++;
            } else if (line[i] == ')') {
                cn = parent[cn];
                h--;
            } else {
                G[cn].pb(nn);
                G[nn].clear();
                val[nn] = line[i]=='T';
                parent[nn] = cn;
                nn++;
            }
            mh = max(h, mh);
        }

        cout << (caso++) << ". " << (dfs(1, mh&1)?"true":"false") << endl;
    }
    return 0;
}
