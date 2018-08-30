#include <bits/stdc++.h>

using namespace std;

int T[7];

int main(int nargs, char **args) {
    clock_t _inicio = clock();

	int t, n, nc, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);

		int win = -1, wcnt = 0, wpunt = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &nc);
			memset(T, 0, sizeof T);
			for (int j = 0; j < nc; j++) {
				scanf("%d", &x);
				T[x]++;
			}

			int punt = nc;

			sort(T, T + 7);
			for (int j = 1, ac = 0; j <= 3; j++) {
				punt += max(0, T[j] - ac)*(4 - j + (j==1));
				ac = T[j];
			}

			if (punt > wpunt) {
				wpunt = punt;
				win = i;
				wcnt = 1;
			} else if (punt == wpunt) {
				wcnt++;
			}
		}

		if (wcnt == 1) {
			if (win == 1) puts("chef");
			else printf("%d\n", win);
		} else puts("tie");
	}

    fprintf(stderr, "Time elapsed: %.3f ms\n", (clock() - _inicio)/1000.0);
    return 0;
}
