#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int A[MAXN], B[MAXN];

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", A + i);
        }
        
        sort(A, A + n);
        
        int a = 0, b = n -1, ind = 0;
        
        // Primero todos los ceros
        while (A[ind] == 0) {
            B[a++] = A[ind++];
        }

        bool left = 1;
        for (int j; ind < n; ) {
            j = ind;
            while (j < n && A[j] == A[ind]) j++;
            while (ind < j) {
                if (left) {
                    B[a++] = A[ind];
                } else {
                    if (B[b+1] != A[ind]) {
                        B[b--] = A[ind];
                    } else {
                        B[a++] = A[ind];
                    }
                }
                left = !left;
                ind++;
            }
        }
        
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            ans += B[i]*B[i-1];
        }
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            cout << B[i] << (i+1==n?"\n":" ");
        }
    }
    return 0;
}