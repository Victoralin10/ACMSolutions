#include <bits/stdc++.h>

#define MAXN 10

using namespace std;
char sa[MAXN], sb[MAXN], ea[MAXN], eb[MAXN];

int t, n, m;
int memo[2][1<<10][1<<10][26];

bool dp(int turn, int maska, int maskb, char prev) {
    // cout << turn << " " << maska << " " << maskb << " " << prev << endl;
    if (prev == '*') {
        bool ans = 0;
        for (int i = 0; i < n; i++) {
            ans |= !dp(1 - turn, maska^(1<<i), maskb, ea[i]);
        }
        return ans;
    }

    if (memo[turn][maska][maskb][prev - 'a'] != -1) {
        return memo[turn][maska][maskb][prev - 'a'];
    }

    bool ans = 0;
    if (turn == 0) {
        for (int i = 0; i < n; i++) {
            if ((maska&(1<<i)) && sa[i] == prev) {
                ans |= !dp(1 - turn, maska^(1<<i), maskb, ea[i]);
            }
        }
    } else {
        for (int i = 0; i < m; i++) {
            if ((maskb&(1<<i)) && sb[i] == prev) {
                ans |= !dp(1 - turn, maska, maskb^(1<<i), eb[i]);
            }
        }
    }

    // cout << turn << " " << maska << " " << maskb << " " << prev << " " << ans << endl;
    return memo[turn][maska][maskb][prev - 'a'] = ans;
}

int main(int nargs, char **args) {
    cin >> t;
    string line;
    for (int caso = 1; caso <= t; caso++) {
        cin >> n;
        getline(cin, line);
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            sa[i] = line[0];
            ea[i] = line[(int)line.size() - 1];
        }

        cin >> m;
        getline(cin, line);
        for (int i = 0; i < m; i++) {
            getline(cin, line);
            sb[i] = line[0];
            eb[i] = line[(int)line.size() - 1];
        }

        memset(memo, -1, sizeof memo);
        cout << "Game " << caso << ": player" << (dp(0, (1<<n) - 1, (1<<m) - 1, '*')?"1":"2") << endl;
    }
 
    return 0;
}
