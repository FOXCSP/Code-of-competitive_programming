#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 200010;
const ll mod = 998244353;
ll dp[N][2], n, a[N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < 2)
			ans += a[i];
		else {
			if (a[i] < 2)
				ans += a[i];
			else {
 				ans = (ans * a[i]) % mod;
			}
		}
	}
	cout << (ans % mod) << '\n';
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
