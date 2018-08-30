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


int main(int nargs, char **args) {
    clock_t _inicio = clock();
    
    int t;
    string line;

    cin >> t;
    getline(cin, line);


    while (t--) {    
        getline(cin, line);

        int cnt[30];
        clr(cnt, 0);

        for (char c: line) {
            if (c == ' ') continue;
            cnt[c - 'A']++;
        }

        vector <pair <int, int> > freqs;
        REP(i, 26) {
            freqs.push_back({cnt[i], i});
        }
        sort(all(freqs));
        if (freqs[25].first == freqs[24].first) {
            cout << "NOT POSSIBLE" << endl;
        } else {
            int d = freqs[25].second - 4;
            if (d < 0) {
                d += 26;
            }
            string ans = "";
            for (char c: line) {
                if (c == ' ') {
                    ans.push_back(' ');
                } else {
                    ans.push_back('A' + (c - 'A' - d + 26)%26);
                }
            }
            cout << d << " " << ans << endl;
        }
    }

    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
