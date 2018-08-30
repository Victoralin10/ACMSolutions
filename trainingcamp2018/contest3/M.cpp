#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;

#define MAXN 500005

vector <pair <int, char> > G[MAXN];
int n, m;
char s[MAXN];
bool ans = false;
int a = -1, b = -1;

pair <Pair, Pair> dfs(int nodo, int parent = -1) {
    if (G[nodo].size() == 1 && parent > 0) {
        return {{-1, nodo}, {m, nodo}};
    }

    Pair mn = {-2, 0}, mx = {m+1, 0};
    vector <pair <Pair, int> > vmn, vmx;
    for (auto x: G[nodo]) {
        if (x.first == parent) {
            continue;
        }

        pair <Pair, Pair> sub = dfs(x.first, nodo);
        Pair cmn = sub.first, cmx = sub.second;
        if (cmn.first < m - 1 && s[cmn.first + 1] == x.second) {
            cmn.first++;
        }
        if (cmx.first > 0 && s[cmx.first - 1] == x.second) {
            cmx.first--;
        }
        mn = max(cmn, mn);
        mx = min(cmx, mx);
        vmn.push_back({cmn, x.first});
        vmx.push_back({cmx, x.first});
    }
    if (vmx.size() > 1) {
        pair <Pair, int> mn1 = {{-10, -10}, -1}, mn2 = {{-10, -10}, -1};
        for (auto x: vmn) {
            if (x > mn1) {
                mn2 = mn1;
                mn1 = x;
            } else if (x > mn2) {
                mn2 = x;
            }
        }

        for (auto x: vmx) {
            if (x.second != mn1.second) {
                if (x.first.first - 1 <= mn1.first.first) {
                    ans = true;
                    b = x.first.second;
                    a = mn1.first.second;
                }
            } else {
                if (x.first.first - 1 <= mn2.first.first) {
                    ans = true;
                    b = x.first.second;
                    a = mn2.first.second;
                }
            }
        }
    }
    for (int i = 0; i < vmn.size(); i++) {
        if (vmn[i].first.first + 1 == m) {
            b = nodo;
            a = vmn[i].first.second;
        }
        if (vmx[i].first.first == 0) {
            a = nodo;
            b = vmx[i].first.second;
        }
    }

    return {mn, mx};
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    scanf("%d%d", &n, &m);

    char c;
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d%d%s", &u, &v, s);
        c = s[0];
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }
    scanf("%s", s);

    dfs(1);
    cout << a << " " << b << endl;

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
