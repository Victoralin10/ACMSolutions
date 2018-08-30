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

char A[100005], B[100005];

int main(int nargs, char **args) {
    int n;
    scanf("%d%s%s", &n, A, B);

    int cnt[] = {0, 0}, a, cnt2[] = {0, 0};
    Long ans = 0;
    REPR(i, 0, n) {
        a = (A[i] - '0') | (B[i] - '0');
        if (a == 0) {
            ans += cnt[1];
        } else if (B[i] == '0') {
            ans += cnt[0];
        } else if (A[i] == '1') {
            ans += cnt2[0];
        } else if (A[i] == '0') {
            ans += cnt2[1];
        }
        cnt[A[i] - '0']++;
        if (B[i] == '0') {
            cnt2[A[i] - '0']++;
        }
    }
    cout << ans << endl;

    cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
