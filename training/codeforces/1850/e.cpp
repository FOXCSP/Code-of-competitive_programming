#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define pb push_back
#define P __int128
#define se second
#define fi first
using namespace std;
using ll = long long;

const int N = 200010;
int n;
int mp[N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x <= n) {
			mp[x]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int p = i;
		int res = 0;
		for (int j = 1; j <= p / j; j++) {
			if (p % j == 0) {
				res += mp[j];
				if (j != (p / j)) {
					res += mp[p / j];
				}
			}
		}
		ans = max(ans, res);
	}
	cout << ans << '\n';
	for (int i = 0; i < N; i++) mp[i] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int _ = 1;
	cin >> _;
	for (; _--; ) {
		solve();
	}
	return 0;
}
