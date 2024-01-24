#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

const int N = 2e5 + 10;
ll a[N], c[3][N];
int n, m;
void add(ll op, ll x,ll y) {
	for(; x <= n; x += x & -x) c[op][x] += y;
}
ll ask(ll op, ll x) {
	ll res = 0;
	for(; x; x -= x & -x) res += c[op][x];
	return res;
}

void modify(int l, int r, int d) {
	add(0, l, d);
	add(0, r + 1, -d);
	add(1, l, l * d);
	add(1, r + 1, -(r + 1) * d);
}

int query(int l, int r) {
	ll ans = (r+1)*ask(0, r) - ask(1, r);
	ans -= l*ask(0, l-1) - ask(1, l-1);
	return ans;
}

void solve() {
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n;i ++) {
		scanf("%lld", &a[i]);
	}
	for (int i = n; i >= 1; i--) {
		a[i] = a[i] - a[i - 1];
	}

	for (int i = 1; i <= n; i++) {
		modify(i, i, a[i]);
	}
	
	while(m--) {
		int op, l, r, k, d;
		scanf("%lld",&op);
		if(op == 2) {
			int q;
			scanf("%lld", &q);
			printf("%lld\n", query(1, q));
		}
		else {
			scanf("%lld%lld%lld%lld", &l, &r, &k, &d);
			modify(l, l, k);
			if (l < r) modify(l + 1, r, d);
			if (r < n) modify(r + 1, r + 1, -(k + d * (r - l)));
		}
	}
}

signed main() {
	solve();
	return 0;
}