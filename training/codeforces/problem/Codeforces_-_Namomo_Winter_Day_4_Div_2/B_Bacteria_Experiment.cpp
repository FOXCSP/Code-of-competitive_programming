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
#define VPP vector<pii>
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
inline ll read() {
	ll s=0,f=1; char c = getchar();
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while ('0'<= c&&c<='9') {s=s*10+c-'0';c=getchar();}
	return s*f;
}
void print(ll x) {if (!x) return ; if (x>9) print(x/10); putchar(x%10+'0');}
const int Mod = 1e9+7;
// --head--

const int N = 500010;
int n, cnt;
VI e[N];
bool st[N];
PII bfs(int start) {
	PII ans = {0, 0};
	queue<PII> q;
	q.push({0, start});
	memset(st, 0, sizeof st);
	while (!q.empty()) {
		auto [d, u] = q.front(); q.pop();
		if (st[u]) continue;
		st[u] = 1;
		for (auto v : e[u]) {
			if (!st[v]) {
				q.push({d + 1, v});
				if (d + 1 > ans.fi) ans = {d + 1, v};
			}
		}
	}
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
	}
	auto a = bfs(1);
	auto b = bfs(a.se);
	int d = b.fi;
	int ans = 0;
	while ((1 << ans) < d) ans++;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	solve();
	return 0;
}