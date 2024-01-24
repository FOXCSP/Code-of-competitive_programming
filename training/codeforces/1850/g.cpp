#include <bits/stdc++.h>
#define SZ(T) (int)(T.size())
#define pb push_back
#define P __int128
#define se second
#define fi first
using namespace std;
using ll = long long;

const int N = 200010;
void solve() { 
	int n;
	cin >> n;
	map<int, int> a, b, c, d;
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		res += a[x]++;
		res += b[y]++;
		res += c[x+y]++;
		res += d[y-x]++;
	}
	cout << 2ll * res << '\n';
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
