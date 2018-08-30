#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

typedef long long Long;
typedef vector<int> vInt;
typedef vector<vInt> vvInt;
typedef vector<string> vStr;
typedef pair<int, int> Pair;
typedef vector<pair<int, int> > vPair;


Long fastpow(Long a, Long b, Long c) {
    Long p = a;
    Long ans = 1;
    while (b) {
        if (b&1) ans = (ans * p)%c;
        b >>= 1;
        p = (p * p)%c;
    }
    return ans;
}

int main(int nargs, char **args) {
    //clock_t _inicio = clock();
    int n;
    cin >> n;    
    cout << fastpow(8, n, 10);
    //fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
