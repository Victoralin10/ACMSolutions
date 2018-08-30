#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

vector <int> G[1000];

int getId(char c) {
    if (c == '.') return 0;
    return c - 'A' + 1;
}

char toId(int a) {
    if (!a) return '.';
    return 'A' + a - 1;
}

int getKey(char a, char b) {
    return getId(a)*27 + getId(b);
}

pair <char, char> toKey(int n) {
    return {toId(n/27), toId(n%27)};
}

string ans = "";

void dfs(int nodo) {
    char x = toId(nodo%27);
    while (SZ(G[nodo])) {
        int next = G[nodo][SZ(G[nodo]) - 1];
        G[nodo].pop_back();
        dfs(next);
    }
    ans.push_back(x);
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    int t;
    cin >> t;
    while (t--) {
        REP(i, 1000) {
            G[i].clear();
        }

        string line = "", copia;
        cin >> copia;
        REP(i, SZ(copia)) {
            if (isdigit(copia[i])) {
                int j = i, n = 0;
                while (j < SZ(copia) && isdigit(copia[j])) {
                    n = n*10 + (copia[j] - '0');
                    j++;
                }
                while (--n) {
                    line.push_back(copia[i-1]);
                }
                i = j-1;
            } else {
                line.push_back(copia[i]);
            }
        }
        copia = line;
        sort(all(copia));

        vector <int> pares;
        int l = line.size();
        REP(i, l) {
            pares.push_back(getKey(line[i], copia[i]));
        }
        sort(all(pares));
        REP(i, l) {
            auto sp = toKey(pares[i]);
            char a = line[i], b = sp.first, c = sp.second;
            G[getKey(a, b)].push_back(getKey(b, c));
        }

        ans = "";
        dfs(pares[0]);
        reverse(all(ans));
        cout << ans.substr(0, l) << endl;
    }
    
    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
