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
const int Maxn = 200010, Maxm = 1000010;


void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int t = abs(c - b) + c;
	if(a > t) cout << "2\n";
	else if(a < t) cout << "1\n";
	else cout << "3\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}