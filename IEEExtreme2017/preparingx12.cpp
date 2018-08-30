#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
#define oo 1<<30

int id = 0;
int T[MAXN], B[MAXN];
map <string, int> idBook;

int dp[2][1<<20];

int main() {
    int b = 0;
    string line;
    while (getline(cin, line)) {
        stringstream io(line);

        io >> T[b];
        while (io >> line) {
            if (idBook.find(line) == idBook.end()) {
                idBook[line] = id++;
            }
            B[b] ^= (1<<idBook[line]);
        }
        b++;
    }

    for (int i = (1<<id) - 1; i >= 0; i--) {
        dp[0][i] = oo;
    }
    dp[0][0] = 0;

    for (int i = 0, ind; i < b; i++) {
        ind = !(i&1);
        for (int j = (1<<id) - 1; j >= 0; j--) {
            // cout << dp[!ind][j] << " ";
            // cout << (j^(j&B[i])) << ":" << dp[!ind][(j^(j&B[i]))] << " ";
            dp[ind][j] = min(dp[!ind][j], T[i] + dp[!ind][j^(j&B[i])]);
        }
        // cout << endl;
    }

    cout << dp[b&1][(1<<id) - 1] << endl;
}