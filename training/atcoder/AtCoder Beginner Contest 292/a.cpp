#include <bits/stdc++.h>
#define fi first
#define se second
#define lp (p<<1)
#define rp (p<<1|1)
#define pb emplace_back
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setop(T) cout<<fixed<<setprecision(T);
using namespace std;

void solve(int caseT) {
	string s;
	cin >> s;
	for (auto c:s) {
		if (c > 'Z') c -= 32;
		cout << c;
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _;
	_=1;	
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}