#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 100010;
int s[N], n, k;

void solve() {
	cin >> n >> k;
	for(int i = 1; i <= k; i ++) cin >> s[i];
	s[k + 1] = 2e9;
	for(int i = k; i > 1; i --) {
		s[i] -= s[i - 1];
		if(s[i] > s[i + 1]) {
			cout << "No\n";
			return ;
		}
	}
	int va = n - k + 1;
	if(1ll * va * s[2] < s[1]) cout << "No\n";
	else cout << "Yes\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int ca; cin >> ca;
	while(ca --) { 
		solve();
	}
	return 0;
}