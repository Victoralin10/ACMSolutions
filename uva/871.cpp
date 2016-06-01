/**
* Title:            (871 - Counting Cells in a Blob)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

int dr[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dc[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool isValid(vector <string> &blob, int r, int c) {
    return r >= 0 && r < blob.size() && c >= 0 && c < blob[0].size();
}

int getSize(vector <string> &blob, int r, int c) {
    queue <pair<int, int> > Q;

    Q.push(make_pair(r, c));
    blob[r][c] = '0';

    int ans = 0;
    while (!Q.empty()) {
        pair <int, int> q = Q.front();
        Q.pop();
        ans++;

        for (int i = 0; i < 8; i++) {
            int nr = q.first + dr[i];
            int nc = q.second + dc[i];

            if (isValid(blob, nr, nc) && blob[nr][nc] == '1') {
                Q.push(make_pair(nr, nc));
                blob[nr][nc] = '0';
            }
        }
    }
    return ans;
}

int countCells(vector <string> &blob) {
    if (blob.empty() || blob[0].empty()) {
        return 0;
    }

    int R = blob.size(), C = blob[0].size();

    int ans = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (blob[r][c] == '1') {
                ans = max(ans, getSize(blob, r, c));
            }
        }
    }

    return ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int tc;
    cin >> tc;

    string line;
    getline(cin, line);
    getline(cin, line);

    bool firstCase = true;
    while (tc--) {
        vector <string> blob;
        while (getline(cin, line) && line != "") {
            blob.push_back(line);
        }
        if (!firstCase) {
            cout << endl;
        }

        cout << countCells(blob) << endl;
        firstCase = false;
    }
    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
