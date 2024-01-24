#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 10;

int w[N];
long long sum;
void solve() {
	int n;
	cin >> n;
	bool f1 = true;
	bool f2 = true;
	int minx = 2e9, maxx = -2e9;
	sum = 0;
	for(int i = 1;i <= n;i ++) {
		cin >> w[i];
		if(w[i] < 0) f1 = false;
		if(w[i] > 0) f2 = false;
		minx = min(minx, w[i]);
		maxx = max(maxx, w[i]);
		sum += abs(w[i]);
	}

	if(n == 1) {
		if(f1) cout << sum << '\n';
		else if(f2) cout << -sum << '\n';
		return ;
	}
	if(f1) {
		cout << ll(sum - 1ll * 2 * minx) << '\n';
	}
	else if(f2)
		cout << ll(sum - 1ll * 2 * abs(maxx)) << '\n';
	else
		cout << sum << '\n'; 
}


int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	while(t --) solve();
	return 0;
}