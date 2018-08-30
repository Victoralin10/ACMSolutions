#include <iostream>
#include <cmath>
#include <cstring>

#define MAXN 100005

using namespace std;

int C[MAXN];

int main() {
    int t;
    long long a, b, d;
    cin >> t >> a >> b;
    while (t--) {
        cin >> d;
        memset(C, 0, sizeof C);

        int rb = (int)sqrt(b + 0.5);
        for (int i = 1; i <= rb; i++) {
            bool di = (i%d != 0);
            long long ji = (a - 1)/i + 1, i2 = (long long)i*i;
            for (long long j = i*((a-1)/i + 1); j <= b; j += i, ji++) {
                if (i2 > j) continue;
                C[j - a] += di;
                if (ji > i && ji <= j && d*(ji/d) != ji) C[j - a]++;
            }
        }

        long long ans = 0;
        for (int i = b-a; i >= 0; i--) {
            ans += C[i];
        }
        cout << ans << endl;
    }    
}
