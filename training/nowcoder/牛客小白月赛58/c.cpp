#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 200010;
int a[N], sum = 0, ans, idx;
map<int,int> mp, op;
vector<vector<int>> v;

void init() {
    idx = ans = sum = 0;
    mp.clear(), op.clear(), v.clear();
}

void solve() {
	int n, m; cin >> n >> m;
    init();
	v.resize(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
		mp[a[i]] ++;
		int x = a[i] % m;
		if(!op[x]) op[x] = ++ idx;
		v[op[x]].push_back(i);
	}
	for(int i = 1; i <= n; i ++) {
		int x = (sum - a[i]) % m;
		for(auto c : v[op[x]]) {
			if(c != i) {
				int y = (a[c] + a[i]) % m;
				if(y == 0) {
					cout << m << '\n'; return ;
				}
				ans = max(ans, y);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}