#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100010;
int a[N];
std::vector<pair<int,int>> v;
void solve() {
	int n;
	cin >> n;
	v.clear();
	for(int i = 1;i <= n;i ++) cin >> a[i];
	int cnt = 0;
	if(a[1] != a[n]) {
		v.push_back({1, n});
		if((a[1] + a[n]) % 2 == 0 ) a[1] = a[n];
		else a[n] = a[1];
		cnt ++;
	}
	for(int i = 2; i < n; i ++) {
		if((a[i] + a[1]) % 2 != 0) {
			v.push_back({1, i});
			cnt ++;
		}
		else {
			v.push_back({i, n});
			cnt ++;
		}
	}
	cout << cnt << '\n';
	for(auto c : v) {
		cout << c.first << " " << c.second << '\n';
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}