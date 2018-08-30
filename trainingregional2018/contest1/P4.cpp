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

Pair A[10004];

int main(int nargs, char **args) {
    int n, l;
    while (cin >> n >> l) {
        REP(i, n) cin >> A[i].second >> A[i].first;
        sort(A, A + n);

        priority_queue <int> st1, st2;
        int d = 0, ans = 0, j = 0;
        REP(i, 10001) {
            if (j == n) break;
            while (j < n && A[j].first <= i) {
                st2.push(A[j++].second);
            }
            int cl = l;
            while (cl > 0 && !st2.empty()) {
                int tp = st2.top(); st2.pop();
                ans += tp;
                cl--;
                st1.push(-tp);
            }
            while (d > 0 && !st2.empty()) {
                int tp = st2.top(); st2.pop();
                ans += tp;
                d--;
                st1.push(-tp);
            }
            while (!st2.empty()) {
                int tp = st2.top(); st2.pop();
                if (st1.empty()) continue;

                int xtp = st1.top();
                if (tp > -xtp) {
                    ans += tp + xtp;
                    st1.pop();
                    st1.push(-tp);
                }
            }
            d += cl;
        }
        cout << ans << endl;
    }
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
