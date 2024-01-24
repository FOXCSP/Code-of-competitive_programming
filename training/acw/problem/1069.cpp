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
const int N = 55, M = 1000010;

struct HP {
	long long p[30], len;
	HP(int x = 0) {
		memset(p, 0, sizeof p);
		len = 0;
		while(x) p[++ len] = x % 10, x /= 10;
	}

	void print() {
		lep(i, len, 1) cout << p[i];
		cout << '\n';
	}

	HP operator + (const HP b) const {
		HP c = HP(0);
		int l = max(len, b.len);
		for(int i = 1, t = 0; i <= l || t; i ++) {
			t += p[i] + b.p[i];
			c.p[++ c.len] = t % 10;
			t /= 10;
		}
		return c;
	}
	HP operator * (const int b) const {
		HP c = HP(0);
		long long t = 0;
		for(int i = 1;i <= len || t; i ++) {
			t += p[i] * (ll)b;
			c.p[++ c.len] = t % 10;
			t /= 10;
		}
		return c;
	}
} f[N][N];

HP min(HP a, HP b) {
	if(a.len < b.len) return a;
	if(a.len > b.len) return b;
	lep(i, a.len, 1) {
		if(a.p[i] < b.p[i]) return a;
		else if(a.p[i] > b.p[i]) return b;
	}
	return a;
}

int n, w[N];
HP base = HP(1);
void debug() {
	HP((HP(120021)) + (HP(9900))).print();
}

void solve() {
	cin >> n;
	rep(i, 1, n) cin >> w[i];
	rep(len, 3, n) {
		rep(i, 1, n - len + 1) {
			int j = i + len - 1;
			f[i][j] = f[i][i + 1] + f[i + 1][j] + base * w[i] * w[i + 1] * w[j];
			rep(k, i + 2,j - 1)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j] + base * w[k] * w[i] * w[j]);
		}
	}
	f[1][n].print();
}

int main() {
clock_t c1;
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
end:
	cerr << "\nTime used:" << clock_t() - c1 << "ms\n";
	return 0;
}