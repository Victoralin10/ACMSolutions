#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define endl "\n"

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;

string s;

int main(int nargs, char **args) {
    int t, sx, sy, ex, ey;
    scanf("%d%d%d%d%d", &t, &sx, &sy, &ex, &ey);
    cin >> s;
    Long x = sx;
    Long y = sy;
    Long tm = -1;
    REP (i, t) {
        if (x == ex && y == ey) {
            tm = i;
            break;
        }
        char o = s[i];
        if (o == 'E') {
            x++;
        } else if (o == 'S') {
            y--;
        } else if (o == 'W') {
            x--;
        } else {
            y++;
        }
        cout << x  << " "<< y << endl;
    }
    if (x == ex && y == ey) {
        tm = t;
    }
    cout << tm << endl;
}
