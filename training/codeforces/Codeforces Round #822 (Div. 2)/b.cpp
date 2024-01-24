#include <bits/stdc++.h>

using namespace std;

const int N = 550;
void solve() {
	int n;
	cin >> n;
	int g[N][N];
	for(int i = 1;i <= n;i ++)
	    for(int j = 1; j <= i;j ++)
	        g[i][j] = 0;
	for(int i = 1; i <= n;i ++) {
		for(int j = 1;j <= i;j ++) {
			if(j == 1 || j == i) g[i][j] = 1;
		}
	}
	for(int i = 1;i <= n;i ++) {
		for(int j = 1; j <= i;j ++)
			cout << g[i][j] << " ";
		cout << "\n";
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	while(t --) solve();
	return 0;
}