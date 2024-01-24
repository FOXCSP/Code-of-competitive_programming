#include <bits/stdc++.h>

using namespace std;
using ll = long long;

std::vector<int> res;
void solve() {
	int n, x, y;
	res.clear();
	cin >> n >> x >> y;
	if(x < y) swap(x, y);
	if(y != 0 || x == 0) cout << "-1\n";
	else {
		if(x == 1) {
			for(int i = 1; i < n; i ++) cout << i + 1 << " \n"[i == n - 1];
		}
		else if(n % x != 1) cout << "-1\n";
		else {
			int now = 1;
			for(int i = 1;i < n;) {
				if(i == 1) {
					int t = 0;
					while(t < n && t < x) res.push_back(1), t ++;
					i += (x + 1);
				}
				else {
					int t = 0;
					while(t < x) res.push_back(i), t ++;
					i += x;
				}
			}
			for(auto c : res) cout << c << " ";
			cout << '\n';
		}
	}
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}