#include <bits/stdc++.h>

using namespace std;

#define MAXN 2501

bitset <MAXN*MAXN> T;
int t, w, h;
int A[MAXN], B[MAXN];

const int mxn = 10;

int main() {
    string line;
    cin >> t;
    while (t--) {
        cin >> h >> w;
        if (h < w) {
            for (int i = 0; i < h; i++) {
                cin >> line;
                for (int j = 0; j < w; j++) {
                    T[i*w + j] = (line[j] != '.');
                }
            }
        } else {
            for (int i = 0; i < h; i++) {
                cin >> line;
                for (int j = 0; j < w; j++) {
                    T[j*h + i] = (line[j] != '.');
                }
            }
            swap(h, w);
        }

        bool ok = 1;
        for (int dh = 3; dh <= mxn && dh <= h && ok; dh++) {
            memset(A, 0, sizeof A);
            for (int j = 0; j < dh; j++) {
                for (int k = 0; k < w; k++) {
                    A[k] += T[j*w + k];
                }
            }
            for (int j = dh-1; j < h && ok; j++) {
                memset(B, 0, sizeof B);
                for (int k = 0; k < w; k++) {
                    B[k+1] = B[k] + A[k];
                }
                for (int k = dh; k <= w; k++) {
                    if (B[k] - B[k-dh] >= dh) {
                        ok = 0;
                        break;
                    }
                }

                for (int k = 0; k < w; k++) {
                    A[k] += T[(j+1)*w + k];
                    A[k] -= T[(j-dh+1)*w + k];
                }
            }
        }

        puts(ok?"YES":"NO");
    }
}