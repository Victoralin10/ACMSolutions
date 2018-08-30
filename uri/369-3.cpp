#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

clock_t _inicio = clock();

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

int main(int nargs, char **args) {
    string key, line;
    int t;
    cin >> key >> t;
    getline(cin, line);
    string vowels = "aeiou";

    while (t--) {
        getline(cin, line);

        int d = 0, a, b;
        for (int i = 0, j; i < SZ(line) && line[i] != ' '; i++) {
            j = i;
            bool enc = vowels.find(line[i]) > 5;
            while (j < SZ(line) && line[j] != ' ') {
                if (enc) {
                    a = line[j] - 'a', b = key[d] - 'a';
                    line[j] = 'a' + (a+b)%26;
                    d++;
                    if (d == SZ(key)) d = 0;
                }
                j++;
            }
            i = j;
        }

        cout << line << endl;
    }
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
