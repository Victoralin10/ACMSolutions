#include <bits/stdc++.h>
#define MAXN 1003

using namespace std;

pair <int, string> A[MAXN];

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

	for (int j, ncaso = 1;; ncaso++) {
		cin >> j;
		if (j == 0) break;

		cout << "Teste " << ncaso << endl;
		string name;
		for (int i = 0; i < j; i++) {
			int suma = 0, mn = (1<<30), mx = 0;
			cin >> name;

			for (int k = 0, x; k < 12; k++) {
				cin >> x;
				suma += x;
				mn = min(mn, x);
				mx = max(mx, x);
			}
			A[i] = make_pair(-suma + mn + mx, name);
		}

		sort(A, A + j);
		int ord = 1;
		for (int i = 0; i < j; i++) {
			if (i > 0 && A[i].first != A[i-1].first) {
				ord = i + 1;
			}
			cout << ord << " " << -A[i].first << " " << A[i].second << endl;
		}

		cout << endl;
	}


    // fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
