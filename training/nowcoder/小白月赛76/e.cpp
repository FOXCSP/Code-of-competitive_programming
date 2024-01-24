#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 200010;
const ll mod = 998244353;
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "#" + s;
	pair<char, ll> now;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (now.se == 0) {
			now.fi = s[i], now.se = 1;
			continue;
		}
		if (s[i] == '(') {
			// (
			if (now.fi == '(') now.se++;
			if (now.fi == ')') {
				ans += now.se;
				now.se--;
			}
		} else {
			// )
			if (now.fi == ')') now.se++;
			if (now.fi == '(') {
// 				ans += now.se - 1;
				now.se--;
			} 
		}
	}
    if (now.se != 0)
        cout << "-1\n";
    else
        cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _ = 1;
	cin >> _;
	
	for ( ; _--; )
		solve();
	return 0;
}
