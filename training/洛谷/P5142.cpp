#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T> 
using namespace std;
typedef long long ll;
const int N = 100010;
const ll mod = 1000000007;

int n, m;
int a[N];
struct seg {
	ll sum1;
	ll sum2;
} tr[N * 4];

seg operator + (const seg L, const seg R) {
	return (seg){(L.sum1 + R.sum1) % mod, (L.sum2 + R.sum2) % mod};
}

void pushup(int p) {
	tr[p] = tr[lp] + tr[rp];
}

void build(int p, int l,int r) {
	if (l == r) {
		tr[p].sum1 = a[l];
		tr[p].sum2 = 1LL * a[l] * a[l] % mod;
	} else {
		int mid = (l + r) / 2;
		build(lp, l, mid);
		build(rp, mid + 1, r);
		pushup(p); 
	}
}

void modify(int p, int l, int r, int x, int y) {
	if (l == r) {
		tr[p].sum1 = y;
		tr[p].sum2 = 1LL * y * y % mod;
	} else {
		int mid = (l + r) / 2;
		if (x <= mid) modify(lp, l, mid, x, y);
		if (x > mid) modify(rp, mid + 1, r, x, y);
		pushup(p);
	}
}

seg query(int p, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) 
		return tr[p];
	int mid = (l + r) / 2;
	if (ql > mid) return query(rp, mid + 1, r, ql, qr);
	else if (qr <= mid) return query(lp, l, mid, ql, qr);
	else return query(lp, l, mid, ql, qr) + query(rp, mid + 1, r, ql, qr);
}

ll qmi(ll a, ll b) {
	ll res = 1; 
	a %= mod;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;	
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	
	build(1, 1, n);
	
	for (; m--;) {
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1) {
			modify(1, 1, n, x, y);
		} else {
			auto ans = query(1, 1, n, x, y);
			ll len = y - x + 1;
			ll inv = qmi(len * len, mod - 2);
			ll res = (ans.sum2 * inv % mod * len % mod - (ans.sum1 * ans.sum1) % mod * inv % mod + mod) % mod;
			cout << res << '\n';
		}
	}
	return 0;
}
