#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	if(n % 3 == 0) cout << n / 3 << '\n';
	else if(n % 3 == 2) cout << (n + 1) / 3 << '\n';
	else {
		int t = (n + 1) / 3;
		if(!t) t ++;
		cout << t + 1 << '\n';
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T; 
	while(T --) solve();
	return 0;
}