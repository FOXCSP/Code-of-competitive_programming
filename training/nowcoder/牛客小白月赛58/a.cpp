#include <bits/stdc++.h>

using namespace std;

void solve() {
	double m, v, M;
	cin >> M >> m >> v;
	printf("%.2f\n", (m *v) / (M - m));
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}