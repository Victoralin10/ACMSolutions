/**
* Title:            B. A Lot of Games
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 100005

using namespace std;

map <char, int> T[MAXN];
int nodes = 0;

void add(string s) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (T[cur].find(s[i]) == T[cur].end()) {
            T[cur][s[i]] = ++nodes;
        }
        cur = T[cur][s[i]];
    }
}

int grundy(int node, int tipo) {
    if (T[node].size() == 0) return tipo;

    set <int> st;
    for (map<char, int>::iterator it = T[node].begin(); it != T[node].end();
        it++) {

        st.insert(grundy(it->second, tipo));
    }

    int ans = 0;
    while (st.find(ans) != st.end()) ans++;
    return ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int n, k;
    string pal;

    cin >> n >> k;
    while (n--) {
        cin >> pal;
        add(pal);
    }

    if (grundy(0, 0) == 0) cout << "Second" << endl;
    else if (k == 1) cout << "First" << endl;
    else if (grundy(0, 1) != 0) cout << "First" << endl;
    else if ((k&1)) cout << "First" << endl;
    else cout << "Second" << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
