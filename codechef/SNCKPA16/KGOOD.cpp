/**
* Title:            K-good Words
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t, k;
    cin >> t;
    
    while (t--) {
        string w;
        cin >> w >> k;

        vector <int> frequence(26, 0);
        for (int i = 0; i < w.size(); i++) {
            frequence[w[i] - 'a']++;
        }

        int ans = (1<<30);
        sort(frequence.begin(), frequence.end());

        for (int i = 0, ac = 0; i < 26; i++) {
            int ne = ac;
            for (int j = i + 1; j < 26; j++) {
                ne += max(0, frequence[j] - k - frequence[i]);
            }
            ans = min(ans, ne);
            ac += frequence[i];
        }

        cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
