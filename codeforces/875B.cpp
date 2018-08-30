#include <cstdio>

#define MAXN 300005

int A[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    printf("1");
    for (int i = 0, p, lp = n, cur = 1; i < n; i++) {
        scanf("%d", &p);
        cur++;
        A[p] = 1;
        while (A[lp]) lp--, cur--;
        printf(" %d", cur);
    }
    puts("");
}