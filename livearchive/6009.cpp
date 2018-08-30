#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 100005;

int N, a[kMaxN];

int main() {
	int T;
	cin>>T;
	while (T--) {
		cin>>N;
		long long acum = 0, sum = 0, ans = (1LL<<50);
		for(int i=0; i<N; ++i) {
			cin>>a[i];
			sum = sum + a[i];
		}

		for(int i=0; i<N; ++i) {
			ans = min(ans,acum + sum -a[i]);
			acum += a[i];
		}
		acum = 0;
		for(int i=N-1; i>=0; --i) {
			ans = min(ans,acum + sum -a[i]);
			acum += a[i];
		}

		cout<<ans<<endl;
	}
}
