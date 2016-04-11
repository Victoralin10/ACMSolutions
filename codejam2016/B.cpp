/**
* Title:            Problem B. Revenge of the Pancakes
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

bool isValid(string line) {
    for (string::iterator it = line.begin(); it != line.end(); it++) {
        if (*it == '-') return false;
    }
    return true;
}

int solve(string line) {
    set <string> st;
    st.insert(line);

    queue <pair <string, int> > Q;
    Q.push(make_pair(line, 0));

    while (!Q.empty()) {
        pair <string, int> q = Q.front();
        Q.pop();

        if (isValid(q.first)) return q.second;

        string np = q.first;
        int sf = (int)np.size() - 1;
        while (np[sf] == '+') sf--;
        for (int i = 0; i <= sf; i++) {
            np[i] = (np[i] == '-')?'+':'-';
        }
        reverse(np.begin(), np.begin() + sf + 1);
        if (st.find(np) == st.end()) {
            Q.push(make_pair(np, q.second + 1));
            st.insert(np);
        }

        np = q.first;
        while (sf >= 0 && np[sf] == '-') sf--;
        if (sf < 0) continue;
        for (int i = 0; i <= sf; i++) {
            np[i] = (np[i] == '-')?'+':'-';
        }
        reverse(np.begin(), np.begin() + sf + 1);
        if (st.find(np) == st.end()) {
            Q.push(make_pair(np, q.second + 1));
            st.insert(np);
        }
    }

    return -1;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t;
    string line;

    cin >> t;
    for (int caso = 1; caso <= t; caso++) {
        cin >> line;
        cout << "Case #" << caso << ": " << solve(line) << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
