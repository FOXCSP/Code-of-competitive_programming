#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
typedef double db;
// head
void solve(int CaseT) {
	string s;
	int n;
	cin >> n >> s;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') a++;
		else b++;
	}
	if (a > b) {
		cout << "A\n";
	} else if (a < b) {
		cout << "T\n";
	} else {
		cout << (s.back() == 'A' ? "T" : "A") << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
//	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}
