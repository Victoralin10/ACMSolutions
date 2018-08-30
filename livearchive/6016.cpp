/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1003

using namespace std;

int t, n, m, k;

int M[MAXN][MAXN];
pair <int, int> T[MAXN][4*MAXN];
int B[MAXN][MAXN];

pair <int, int> best(pair <int, int> &a, pair <int, int> &b) {
	if (a.first != b.first) {
		if (a.first > b.first) return a;
		return b;
	}
	if (a.second%m < b.second) {
		return a;
	}
	return b;
}

void update(int id, int nodo, int i, int j, int px, int val) {
	if (px < i || px > j) {
		return;
	}
	if (px == i && px == j) {
		T[id][nodo] = make_pair(val, px);
		return;
	}

	int izq = 2*nodo + 1, der = izq + 1, mid = (i + j)/2;
	update(id, izq, i, mid, px, val);
	update(id, der, mid + 1, j, px, val);
	T[id][nodo] = best(T[id][izq], T[id][der]);
}

pair <int, int> query(int id, int nodo, int i, int j, int a, int b) {
	if (b < i || a > j) return make_pair(-1, 0);
	if (a <= i && j <= b) {
		return T[id][nodo];
	}

	int izq = 2*nodo + 1, der = izq + 1, mid = (i + j)/2;
	pair <int, int> l, r;
	l = query(id, izq, i, mid, a, b);
	r = query(id, der, mid + 1, j, a, b);
	return best(l, r);
}

pair <int, int> makeI(int px) {
	if (2*k - 1 >= m) {
		return make_pair(0, m);
	}

	int a = px - k + 1;
	int b = px + k - 1;
	if (a < 0) {
		a += m;
		b += m;
	}
	return make_pair(a, b);
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    scanf("%d", &t);

    while (t--) {
        scanf("%d%d%d", &n, &m, &k);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &M[i][j]);
			}
		}

		for (int j = 0; j < m; j++) {
			update(0, 0, 0, 2*m - 1, j, M[0][j]);
			update(0, 0, 0, 2*m - 1, j + m, M[0][j]);
		}
		// cerr << query(0, 0, 0, 2*m - 1, 0, m - 1).first << endl;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				pair <int, int> xd = makeI(j), xd2;
				xd2 = query(i-1, 0, 0, 2*m - 1, xd.first, xd.second);
				B[i][j] = xd2.second;
				int prev = xd2.first;
				update(i, 0, 0, 2*m - 1, j, prev + M[i][j]);
				update(i, 0, 0, 2*m - 1, j + m, prev + M[i][j]);
			}
		}

		vector <int> I;
		pair <int, int> q, inter;
		q = query(n-1, 0, 0, 2*m - 1, 0, m -1);

		int ans = q.first, ba = q.second;
		I.push_back(q.second);
		for (int i = n-1; i > 0; i--) {
			ba = B[i][ba]%m;
			I.push_back(ba);
		}

		printf("%d", ans);
		for (int i = n-1; i >= 0; i--) {
			printf(" %d", I[i] + 1);
		}

		printf("\n");
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
