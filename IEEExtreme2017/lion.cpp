#include <cstdio>
#include <algorithm>

 using namespace std;

#define MAXN 1024

int n, m, k;
int rs[MAXN*MAXN], cs[MAXN*MAXN];
int BIT[4*MAXN][4*MAXN];
int XD[4*MAXN][4*MAXN];

int ty(int y) {
    return y + n + 1;
}

int tx(int x) {
    return x + 1;
}

void update(int r, int c, int val) {
    for (int i = r; i < 2*MAXN; i += (i&(-i))) {
        for (int j = c; j < 2*MAXN; j += (j&(-j))) {
            BIT[i][j] += val;
        }
    }
}

int query(int r, int c) {
    int ans = 0;
    for (int i = r; i > 0; i -= (i&(-i))) {
        for (int j = c; j > 0; j -= (j&(-j))) {
            ans += BIT[i][j];
        }
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0, ri, ci, di; i < k; i++) {
        scanf("%d%d%d", &ri, &ci, &di);
        rs[i] = ri; cs[i] = ci;

        int xip = tx(ri + ci), yip = ty(ci - ri);
        update(max(1, xip - di), max(1, yip - di), 1);
        update(xip + di + 1, yip + di + 1, 1);
        update(xip + di + 1, max(1, yip - di), -1);
        update(max(1, xip - di), yip + di + 1, -1);
    }

    

    int mx = -1, nt;
    int best;
    for (int i = 0, xip, yip; i < k; i++) {
        xip = tx(rs[i] + cs[i]);
        yip = ty(cs[i] - rs[i]);
        nt = query(xip, yip);
        if (nt > mx) {
            mx = nt;
            best = i+1;
        }
    }

    printf("%d %d\n", best, mx-1);
}