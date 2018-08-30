#include <bits/stdc++.h>

using namespace std;

int n, m, c;
short int M[25][25];

int dx[] = {1, 1, -1, -1, 1, -1, 0, 0};
int dy[] = {1, -1, 1, -1, 0, 0, 1, -1};

vector <int> next(vector <int> &cur) {
    memset(M, 0, sizeof M);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((cur[i]&(1<<j)) > 0) {
                for (int k = 0; k < 8; k++) {
                    M[(i + dx[k] + n)%n][(j + dy[k] + m)%m]++;
                }
            }
        }
    }

    vector <int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
        for (int j = 0; j < m; j++) {
            if ((cur[i]&(1<<j)) > 0) {
                if ((M[i][j] >= 2 && M[i][j] <= 3)) {
                    ans[i] ^= (1<<j);
                }
            } else {
                if (M[i][j] == 3) {
                    ans[i] ^= (1<<j);
                }
            }
        }
    }
    return ans;
}

void print(vector <int> &cur) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((cur[i]&(1<<j)) > 0) cout << '*';
            else cout << '-';
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m >> c;
    vector <int> ini(n);
    string line;
    for (int i = 0; i < n; i++) {
        cin >> line;
        ini[i] = 0;
        for (int j = 0; j < m; j++) {
            if (line[j] == '-') continue;
            ini[i] ^= (1<<j);
        }
    }

    map <vector <int>, int > myMap;
    myMap[ini] = 0;

    int ni = 0;
    for ( ; ni < c; ni++) {
        ini = next(ini);
        if (myMap.find(ini) != myMap.end()) {
            ni++;
            break;
        }
        myMap[ini] = ni + 1;
    }

    if (ni == c) {
        print(ini);
    } else {
        int period = ni - myMap[ini];
        c = (c - myMap[ini])%period;
        while (c--) {
            ini = next(ini);
        }
        print(ini);
    }

    return 0;
}