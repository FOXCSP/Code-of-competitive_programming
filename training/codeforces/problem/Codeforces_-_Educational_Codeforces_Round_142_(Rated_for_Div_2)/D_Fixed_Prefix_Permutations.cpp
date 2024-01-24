#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define PII pair<int,int>
#define PLL pair<ll, ll>
#define VI vector<int>
#define SZ(x) ((int)x.size())
#define VL vector<ll>;
#define VPP vector<PII>
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--

const int N = 100010;
int son[N * 4][11];
int n, m, idx;
int t[N][11], pos[11];
bool st[11];
int dfs(int u) {
	vector<int> res;
	int ans = 0;
	cout << u << '\n';
	if (SZ(res) == m) {
		int cnt = 0;
		for (int i = 1; i <= m; i++) {
			if (pos[i] == res[i - 1]) cnt++;
		}
		cout << cnt << '\n';
		return cnt;
	}

	for (int i = 1; i <= m; i++) {
		cout << "111\n";
		if (son[u][i] && !st[i]) {
			st[i] = 1;
			cout << "111\n";
			res.pb(i);
			ans = max(dfs(son[u][i]), ans);
			st[i] = 0;
			res.pop_back();
		}
	}
	return ans;
}

void solve() {
	cin >> n >> m;
	idx = 0;
	memset(son, 0, sizeof son);
	for (int i = 1; i <= n; i++) {
		vector<int> a;
		for (int j = 1; j <= m; j++) {
			cin >> t[i][j];
			a.pb(t[i][j]);
		}
		int p = 0;
		for (int k = 0; k < SZ(a); k++) {
			int u = a[k];
			if (!son[p][u]) son[p][u] = ++idx;
			p = son[p][u];
		}
	}
	vector<int> ans;

	auto debug = [&](vector<int> res) {
		cout << "---\n";
		cout << SZ(res) << '\n';
		for (int i = 1; i < SZ(res); i++) {
			cout << res[i] << " \n"[i == SZ(res) - 1];
		}
	};

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pos[t[i][j]] = j;
		}
		ans[i] = dfs(son[0][pos[1]]);
	}
	for (int i = 0; i < SZ(ans); i++) {
		cout << ans[i] << " \n"[i == SZ(ans) - 1];
	}
}

int main() {
	int _;
	cin >> _;
	while (_--)
	solve();
	return 0;
}