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
const int Maxn = 100010, Maxm = 1000010;

int s[Maxn];
int n;
void solve() {
	cin >> n;
	rep(i, 1, n) cin >> s[i];
	rep(i, 1, n) {
		int x;
		cin >> x;
		s[i] -= x;
	}
	sort(s + 1, s + n + 1);
	int l = 1, r = n;
	int ans = 0;
	while(l < r) {
		if(s[l] + s[r] <= 0) l ++, r --, ans ++;
		else r --;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}