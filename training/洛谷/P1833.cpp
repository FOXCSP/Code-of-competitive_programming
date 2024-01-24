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
const int Maxn = 10010, Maxm = 1010;

int f[Maxm], n, m;
struct node {
	int v, w;
};
void solve() {
	int a, b;
	scanf("%d:%d", &a, &b);
	m = 60 * a + b;
	scanf("%d:%d", &a, &b);
	m = 60 * a + b - m;
	scanf("%d", &n);
	rep(i, 1, n) {
		int v, w, s;
		scanf("%d %d %d", &v, &w, &s);
		if(s == 0) {
			rep(j, v, m)
				f[j] = max(f[j], f[j - v] + w);
		}
		else {
			std::vector<node> nodes;
			for(int k = 1; k <= s; k <<= 1)
				nodes.pb({v * k, w * k}), s -= k;
			if(s) nodes.pb({s * v, s * w}); 

			for(auto c : nodes)
				lep(j, m, c.v)
					f[j] = max(f[j], f[j - c.v] + c.w);
		}
	}
	cout << f[m] << '\n';
}

int main() {
	// ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}