#include <bits/stdc++.h>


using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n;
int f[N];

void solve() {
	cin >> n;
	f[0] = 1;
	for(int i = 1;i <= n; i ++) {
		for(int j = i; j <= n; j ++ ) {
			f[j] += f[j - i];
		}
	}
	cout << f[n] << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}