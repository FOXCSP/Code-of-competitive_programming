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

string s;
struct node {
	int id, s;
	bool operator < (const node & B) const {
		return s < B.s;
	}
};
std::vector<node> ans;
void solve() {
	ans.clear();
	cin >> s;
	int l = s.front() - 'a' + 1;
	int r = s.back() - 'a' + 1;
	rep(i, 0, SZ(s) - 1) {
		int t = s[i] - 'a' + 1;
		if(l > r) {
			if(t <= l && t >= r) {
				ans.push_back({i + 1, abs(t - l)});
			}
		}
		if(l < r) {
			if(t <= r && t >= l) {
				ans.push_back({i + 1, abs(t - l)});
			}
		}
	}
	if(l != r) sort(ans.begin() + 1, ans.end() - 1);
	if(l == r) {
		rep(i, 0, SZ(s) - 1) {
			if(s[i] == s[0]) ans.push_back({i + 1, 0});
		}
	}
	cout << abs(l - r) << " " << ans.size() << '\n';
	for(auto c : ans) {
		cout << c.id << " ";
	}
	cout << '\n';

}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}