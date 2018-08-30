/**
* Title:            Jogging Cats
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 50004

using namespace std;

vector <int> G[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int n, m;
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    map <pair <int, int>, int> cnt;

    for (int u = 1; u <= n; u++) {
        vector <int> vec;
        for (int j = 0, v; j < G[u].size(); j++) {
            v = G[u][j];
            if (G[v].size() > 1) vec.push_back(v);
        }
        
        for (int i = 0; i < vec.size(); i++) {
            for (int j = i+1; j < vec.size(); j++) {
                cnt[make_pair(min(vec[i], vec[j]), max(vec[i], vec[j]))]++;
            }
        }
    }

    long long ans = 0;
    for (map <pair <int, int>, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
        ans += (it->second*(it->second - 1))/2;
    }

    cout << ans/2 << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
