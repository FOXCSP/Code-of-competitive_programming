#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define fi first
#define se second

const int N = 200010, M = 100010;
int n;
map<int, int> st;
vector<int> a[M];
void solve() {
	cin >> n;
	st.clear();
	for (int i = 1; i <= n; i++) a[i].clear();
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int x; cin >> x;
			a[i].push_back(x);
			st[x]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		bool f = true;
		for (auto x : a[i]) {
			if (st[x] < 2) {
				f = false;
				break;
			}
		}
		if (f) {
			cout << "Yes\n";
			return ;
		}
	}
	cout << "No\n";
}
int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	int _; cin >> _;
	while(_--) {
		solve();
	}
	return 0;
}