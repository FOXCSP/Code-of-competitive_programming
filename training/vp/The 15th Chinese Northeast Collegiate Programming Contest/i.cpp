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
// head

int p[10] = {0,7,27,41,49,63,78,108};

void solve(int CaseT) {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ans += p[x];	
	}
	if (ans >= 120) ans -= 50;
	else if (ans >= 89) ans -= 30;
	else if (ans >= 69) ans -= 15;
	cout <<ans << '\n';
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
