#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;

const int N = 1e6 + 5;

int tx, ty, n;
map <pair <int, int>, vector < pair <Long, int> > > myMap;

int C[N];

int lis(vector < pair <Long, int> > &pts) {
    sort(pts.begin(), pts.end());

    int l = 0;
    for (pair <double, int> it: pts) {
        if (l == 0 || C[l] < it.second) {
            C[++l] = it.second;
        } else if (C[1] > it.second) {
            C[1] = it.second;
        } else {
            int lo = 1, hi = l, mid;
            while (hi - lo > 1) {
                mid = (hi + lo)>>1;
                if (C[mid] < it.second) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            C[hi] = it.second;
        }
    }
    return l;
}


int main(int nargs, char **args) {
    clock_t _inicio = clock();

    scanf("%d%d%d", &tx, &ty, &n);
    for (int i = 0, x, y, h, g; i < n; i++) {
        scanf("%d%d%d", &x, &y, &h);
        x -= tx;
        y -= ty;
        g = __gcd(abs(x), abs(y));
        Long d = (Long)x*x + (Long)y*y;
        x /= g;
        y /= g;
        myMap[make_pair(x, y)].push_back(make_pair(d, h));
    }

    int ans = 0;
    for (auto  it: myMap) {
        ans += lis(it.second);
    }
    cout << ans << endl;

    // fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
