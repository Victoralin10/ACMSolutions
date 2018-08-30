#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

int N, L;
int T[MAXN][31], ncnt = 0, E[MAXN];
int P[40];
int A[40], B[40], bmask, ac, mnr;

void back(int mask, int cn, int ia, int lmt) {
	if (ia == lmt) {
		if (ac < mnr) {
			for (int i = 0; i < L; i++) {
				A[i] = B[i];
			}
			mnr = ac;
			bmask = mask;
		}
		return;
	}

	for (int i = 1; i <= L; i++) {
		if ((mask&(1<<i))) continue;

		if (T[cn][i] == -1) {
			if (ac < mnr) {
				for (int j = 0; j < L; j++) {
					A[j] = B[j];
				}
				A[ia] = i;
				mnr = ac;
				bmask = mask^(1<<i);
			}
		} else {
			ac += P[ia]*E[T[cn][i]];
			B[ia] = i;
			if (ac < mnr) {
				back(mask^(1<<i), T[cn][i], ia + 1, lmt);
			}
			ac -= P[ia]*E[T[cn][i]];
			B[ia] = 0;
		}
	}
}

int main() {
	int tc = 0;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &L, &N);
		for (int i = 0; i < L; i++) {
			scanf("%d", &P[i]);
		}
		memset(T, -1, sizeof T);
		memset(E, 0, sizeof E);
		ncnt = 0;
		
		for (int na = 0, nl, x, cn; na < N; na++) {
			scanf("%d", &nl);
			cn = 0;
			for (int j = 0; j < nl; j++) {
				scanf("%d", &x);
				if (T[cn][x] == -1) {
					T[cn][x] = ++ncnt;
				}
				cn = T[cn][x];
			}
			E[cn]++;
		}

		mnr = (1<<30);
		ac = 0;
		back(0, 0, 0, min(9, L));
        assert(ac == 0);

		for (int i = 0; i < L && A[i] > 0; i++) {
			if (i > 0) {
				printf(" ");
			}
			printf("%d", A[i]);
		}
		for (int i = 1; i <= L; i++) {
			if ((bmask&(1<<i)) == 0) printf(" %d", i);
		}
		printf("\n");
	}
	// your code goes here
	return 0;
}