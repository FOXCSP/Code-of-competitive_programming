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
	int n, k;
	cin >> n >> k;
	vector<int> a(200, 0), b(200, 0);
	for (int i = 1; i <= k; i++) {
		int op, x;
		cin >> op >> x;
		if (op == 1) {
			a[x]++;
		} else if (op == 2) {
			b[x]++;
		} else {
			if (a[x] >= 2 || b[x]) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
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