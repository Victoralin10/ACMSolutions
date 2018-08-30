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

bool b[30];

int main(int nargs, char **args) {
    ll n, cn;
    int k, ind = 0, cnt = 0, carry = 0, ck = 0;
    cin >> n >> k;
    cn = n;
    while (n) {
        b[ind++] = (n&1);
        cnt += (n&1);
        n >>= 1;
    }
    if (ind > k || cn < k) {
        cout << "No" << endl;
    } else {
        // cout << "Yes" << endl;
        while (ck < k) {
            if (ind >= 0) {
                carry += b[ind];
            }
            if (cnt + carry <= k) {
                cnt += carry;
                carry <<= 1;
            } else {
                int p = k - cnt, q = carry - p;
                carry = 2*p;
                cnt = k;
                ck += q;
                while (q--) {
                    cout << ind << endl;
                }
            }

            ind--;
        }
    }
    
    return 0;
}