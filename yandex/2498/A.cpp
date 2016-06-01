/**
* Title:            (Orthography)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

int compare(string &a, string &b) {
    int ans = abs(a.size() - b.size());
    for (int i = min(a.size(), b.size())-1; i >= 0; i--) {
        ans += a[i] != b[i];
    }
    return ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int n;
    vector <string> words;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }

    string ans = "";
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (compare(words[i], words[j]) > 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = words[i];
            break;
        }
    }

    cout << ans << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
