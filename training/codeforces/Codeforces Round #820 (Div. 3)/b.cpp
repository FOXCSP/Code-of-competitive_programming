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

char get(int x) {
	return char(x - 1 + 'a');
}

void solve() {
	int n;
	cin >> n;
	cin >> s;
	string res = "";
	for(int i = SZ(s) - 1; i >= 0; ) {
		if(s[i] == '0') {
			int t = (s[i - 1] - '0') + (s[i - 2] - '0') * 10;
			res = get(t) + res;
			i = i - 3;
		}
		else {
			res = get(s[i] - '0') + res;
			i --;
		}
	}
	cout << res <<'\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}