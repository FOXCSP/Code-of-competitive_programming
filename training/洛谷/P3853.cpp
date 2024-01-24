#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int a[N];
vector<vector<int>> v;

void solve() {
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	v.resize(n + 1);
	int idx = 0;
	for(int i = 1; i <= n; i ++) {
		bool f = false;
		int len = n, now;
		for(int j = 0; j <= idx; j ++) {
			if(v[j].back() == a[i] - 1) {
				if(len > v[j].size()) {
					now = j, len = v[j].size();
				}
				f = true;
			}
		}
		cout << now << "\n";
		if(f) v[now].push_back(a[i]);
		else v[++ idx].push_back(a[i]);
	}
	int ans = n;
	for(int i = 0; i <= idx; i ++) {
		ans = min(ans, (int)v[i].size());
	}
	cout << ans << '\n';
}

int main() { 
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();
	return 0;
}