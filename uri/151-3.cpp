/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MAXN 10004

using namespace std;

set <int> g[MAXN];
map <string, int> myMap;
int nextId = 0;

void reset() {
	myMap.clear();
	nextId = 0;
	g[0].clear();
	myMap["P. Erdos"] = nextId++;
}

int getId(string s) {
	if (myMap.find(s) != myMap.end()) {
		return myMap[s];
	}
	g[nextId].clear();
	return myMap[s] = nextId++;
}

void addV(int id1, int id2) {
	g[id1].insert(id2);
	g[id2].insert(id1);
}

int N[MAXN];

void bfs() {
	memset(N, -1, sizeof N);

	queue <int> Q;
	Q.push(0);
	N[0] = 0;

	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();

		for (set <int>::iterator it = g[cn].begin(); it != g[cn].end(); it++) {
			if (N[*it] == -1) {
				N[*it] = N[cn] + 1;
				Q.push(*it);
			}
		}
	}
}

bool fnsort(pair <string, int> a, pair <string, int> b) {
	return a.first.substr(3) < b.first.substr(3);
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

	int n, ncaso = 0;
	while (cin >> n) {
		if (n == 0) break;

		cout << "Teste " << ++ncaso << endl;
		reset();
		string s, a, b;
		getline(cin, s);
		for (int i = 0; i < n; i++) {
			getline(cin, s);

			vector <int> ids;
			stringstream io(s);
			while (io >> a >> b) {
				s = a + " " + b.substr(0, (int)b.size() - 1);
				cerr << s << endl;
				ids.push_back(getId(s));
			}

			for (int j = 0; j < ids.size(); j++) {
				for (int k = j + 1; k < ids.size(); k++) {
					addV(ids[j], ids[k]);
				}
			}
		}

		bfs();

		vector <pair <string, int> > ans;
		for (map <string, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
			ans.push_back(make_pair(it->first, N[it->second]));
		}

		sort(ans.begin(), ans.end(), fnsort);

		for (int i = 0; i < ans.size(); i++) {
			if (ans[i].second != 0) {
				cout << ans[i].first << ": ";
				if (ans[i].second > 0) {
					cout << ans[i].second << endl;
				} else {
					cout << "infinito" << endl;
				}
			}
		}
		cout << endl;
	}

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
