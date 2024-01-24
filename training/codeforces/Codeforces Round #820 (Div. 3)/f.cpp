#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define fi first
#define se second
#define pb push_back
#define SZ(a) a.size()
#define rep(i, l, r) for(int i = l; i <= r; i ++)
#define lep(i, r, l) for(int i = r; i >= l; i --)
// #define int long long
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 200010, Maxm = 1000010;

int n, p[N], w, m;
pair<int, int> ans;
string s;

void solve() {
	cin >> s;
	cin >> w >> m;
	n = SZ(s);
	s = "0" + s;
	rep(i, 1, n) p[i] = p[i - 1] + s[i] - '0';

	std::vector<int> a[9];
	for(int i = 1; i + w - 1 <= n; i ++) {
		int x = (p[i + w - 1] - p[i - 1]) % 9;
		a[x].pb(i);
	}
	while(m --) {
		ans = {2e9, 2e9};
		int l, r, k;
		cin >> l >> r >> k;
		int x = p[r] - p[l - 1];
		x %= 9;
		rep(u, 0, 8) {
			if(!SZ(a[u])) continue;
			rep(v, 0, 8) {
				if(!SZ(a[v])) continue;
				if((x * u + v) % 9 == k) {
					if(u == v && SZ(a[u]) > 1) ans = min(ans, {a[u][0], a[u][1]});
					if(u != v) ans = min(ans, {a[u][0], a[v][0]});
				}
			}
		}
		if(ans.fi == 2e9 || ans.se == 2e9) {
			cout << "-1 -1\n";
		}
		else {
			cout << ans.fi << " " << ans.se << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}