#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define P(T) pair<T, T>
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
const int Mod = 1e9+7;
// --head--

const int N = 50010;
vector<int> e[N];
int n, m, d[N];
int st[N], ans = 0;
void dfs(int u) {
	st[u] = 1;
	for (auto v : e[u]) {
		if (st[v]) continue;
		dfs(v);
		ans = max(ans, d[u] + d[v] + 1);
		d[u] = max(d[u], d[v] + 1);
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u = 1;
		for (int j = 2; j <= n / j; j++) {
			if (n % j == 0) {
				u += j;
				if (n / j != j) u += n / j;
			}
		}
		e[i].pb(u);
		e[u].pb(i);
	}
	dfs(1);
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	solve();
	return 0;
}