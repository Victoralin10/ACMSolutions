#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define ll long long
#define ull long long
#define ld long double

#define MOD 1000000007
#define MAXN 10

using namespace std;

int r1[] = {4, 16, 37, 58, 89, 145, 42, 20};

int getSQ(int a) {
    int ans = 0, d;
    while (a) {
        d = a%10;
        a /= 10;
        ans += d*d;
    }
    return ans;
}

int getRoot(int n, set <int> &st) {
    while (st.find(n) == st.end()) {
        st.insert(n);
        n = getSQ(n);
    }

    return n==1;
}

int getI(int n) {
    for (int i = 0; i < 8; i++) {
        if (r1[i] == n) return i;
    }
    return -1;
}

int main(int nargs, char **args) {
    int a, b, ca, cb;
    while (cin >> a >> b) {
        if (a + b == 0) break;
        set <int> fs, ss;
        int ra = getRoot(a, fs);
        int rb = getRoot(b, ss);
        if (ra == rb) {
            int ans = 0;
            ca = a;
            while (ss.find(ca) == ss.end()) {
                ca = getSQ(ca);
                ans++;
            }
            cb = b;
            while (fs.find(cb) == fs.end()) {
                cb = getSQ(cb);
                ans++;
            }

            if (getI(ca) >= 0) {
                int x = abs(getI(ca) - getI(cb));
                ans += min(x, 8 - x) + 2;
                //ans += getI(a)>=0 || getI(b)>=0;
            } else {
                ans += 2;
            }

            cout << a << " " << b << " " << ans << endl;
        } else {
            cout << a << " " << b << " 0" << endl;
        }
    }
    return 0;
}
