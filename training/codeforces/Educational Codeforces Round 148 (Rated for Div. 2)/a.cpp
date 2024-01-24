#include <bits/stdc++.h>
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
	cin >> s;
	int n = SZ(s);
	for (int i = 1; i < n / 2; i++) {
		if (s[i] != s[i - 1]) {
			cout << "YES\n";
			return ;
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _;
	_=1;
	cin>>_;
	for (int i = 1; i <= _; i++)
		solve(i);
	return 0;
}
