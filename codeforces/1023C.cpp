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

const int N = 2e5 + 5;
char S[N], A[N];

int main(int nargs, char **args) {
    int k, n, j = 0, cnt[] = {0, 0};
    cin >> n >> k;
    k = n - k;
    cin >> S;
    REP(i, n) {
        if (S[i] == '(') {
            if (cnt[1]*2 < k){
                cnt[1]++;
            } else {
                A[j++] = '(';
                cnt[0]++;
            }
        } else {
            if (cnt[0]) {
                A[j++] = ')';
                cnt[0]--;
            } else {
                cnt[1]--;
                k -= 2;
            }
        }
    }
    A[j] = 0;
    cout << A << endl;
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
