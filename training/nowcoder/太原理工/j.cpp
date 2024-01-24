#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define P(T) pair<T, T>
#define lp (p<<1)
#define rp (p<<1|1)
#define MP make_pair
#define pb push_back
#define all(T) T.begin(), T.end() 
#define SZ(T) (int)(T.size())
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
ll random(ll x) { return 1ll * rand() * rand() % x; } // srand((unsigned)(time(0)));
string a, b;

int ans = 1e9;

bool ok(string x, string y) {
	int a = 0, b = 0;
	for (auto c : x) a += (c == '1');
	for (auto c : y) b += (c == '1');
//	cout << a << " " << b << " \n";
	return ((5 - SZ(x) + a < b) || (5 - SZ(y) + b < a));
}

void dfs(string x, string y, int cnt) {
	if (ok(x, y)) {
		ans = min(ans, cnt);
	}
	
	if (SZ(x) == 5  && SZ(y) == 5) {
		ans = min(ans, cnt + 2);
	}
	
	if (SZ(x) <= SZ(y)) {
		x.pb('0');
		dfs(x, y, cnt + 1);
		x.pop_back();
		x.pb('1');
		dfs(x, y, cnt + 1);
	} else {
		y.pb('0');
		dfs(x, y, cnt + 1);
		y.pop_back();
		y.pb('1');
		dfs(x, y, cnt + 1);
	}
}

void solve(int CaseT = 1) {
	cin >> a >> b;
	while (a.back() == '?') a.pop_back();
	while (b.back() == '?') b.pop_back();
	if (ok(a, b))	{
		cout << "0\n";
	} else {
		dfs(a, b, 0);
		cout << ans << '\n';
	}
//	cout << ok(a, b) << '\n'; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _;
	_ = 1;
//	cin >> _;
	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
