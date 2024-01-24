#include <bits/stdc++.h>

using namespace std;

const int N = 310;
int a[N], res = -1;
void solve() {
	res = -1;
	map<int,int> mp;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		mp[a[i]] ++;
		if(mp[a[i]] >= 3) res = 0;
	}
	if(res != -1) cout << res << "\n";
	else {
		sort(a + 1, a + n + 1);
		res = 1e9;
		for(int i = 2;i < n;i ++) {
			int t = a[i] - a[i - 1] + a[i + 1] - a[i];
			if(t < res) {
				res = t;
			}
		}
		cout << res << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int t; cin >> t;
	while(t --) 
		solve();
	return 0;
}