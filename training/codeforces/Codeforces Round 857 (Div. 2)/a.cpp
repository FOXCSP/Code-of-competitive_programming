#include <bits/stdc++.h>
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;

int n, m;

void solve(int T) {
	cin >> n;
	map<int, int> mp;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		mp[x]++;
		
	}
	vector<int> t;
	for (int i = 1; i <= 100; i++) {
		if (mp[i] && mp[-i]) {
			t.pb(abs(i));
		}
	}
	m = SZ(t);
	m = m * 2;
	int res = n - m;
	for (int i = 1; i <= res + m / 2; i++) {
		cout << i << " ";
	}
	for (int i = m / 2 + 1, k = 1; i <= m; i++, k++) {
		cout << res + m / 2 - k << " ";
	}
	cout << '\n';
	for (int i = 1; i <= m; i++) {
		if (i & 1) cout << "1 ";
		else cout << "0 ";
	}
	for (int i = 1; i <= res; i++) {
		cout << i << " ";
	}
	cout << '\n';
	
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cin.tie(nullptr);
	int _;
	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}

