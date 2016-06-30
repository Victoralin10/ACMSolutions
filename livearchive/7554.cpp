/**
* Title:            7554 - git
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 6000

using namespace std;

map <string, int> tree[MAXN];
int T[MAXN];
int nodes = 0;

void add(string path, int tipo) {
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '/') path[i] = ' ';
    }
    stringstream io(path);

    int cur = 0;
    while (io >> path) {
        if (tree[cur].find(path) == tree[cur].end()) {
            tree[cur][path] = ++nodes;
            tree[nodes].clear();
            T[nodes] = 2;
        }
        cur = tree[cur][path];
    }
    T[cur] = tipo;
}

int dp[MAXN][2];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    T[0] = 2;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        nodes = 0;
        tree[0].clear();

        string command, path;
        for (int i = 0; i < n; i++) {
            cin >> command >> path;
            add(path, command == "stage");
        }

        for (int node = nodes; node >= 0; node--) {
            if (T[node] < 2) {
                dp[node][T[node]] = 1;
                dp[node][!T[node]] = 0;
                continue;
            }

            int cnt0 = 0, cnt1 = 0;
            for (map <string, int>::iterator it = tree[node].begin();
                it != tree[node].end(); it++) {

                cnt0 += dp[it->second][0];
                cnt1 += dp[it->second][1];
            }

            dp[node][0] = min(cnt0, cnt1 + 1);
            dp[node][1] = min(cnt0 + 1, cnt1);
        }

        cout << dp[0][1] << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
