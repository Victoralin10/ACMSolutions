#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 1024;
const int kInf = (1<<29);

int a[kMaxN], b[kMaxN], N, M;

int main() {
	int T;
	cin>>T;
	while (T--) {
		cin>>N;
		for(int i=0; i<N; ++i) {
			cin>>a[i];
		}
		cin>>M;
		for(int i=0; i<M; ++i)
			cin>>b[i];
		int ans = kInf;
		for(int i=0; i<N; ++i) {
			for(int j=0; j<M; ++j) {
				ans = min(ans, abs(a[i] - b[j]));
			}
		}
		cout<<ans<<endl;
	}
}
