#include <bits/stdc++.h>
#define fi first
#define se second
#define all(T) T.begin(), T.end()
#define pb emplace_back
#define SZ(T) (int)(T.size())
#define lp (p<<1)
#define rp (p<<1|1)
#define P(T) pair<T,T>
#define setop(T) cout<<fixed<<setprecision(T);
using namespace std;

void solve(int caseT) {
	int n;
	cin >> n;
	int cnt = 0;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			a[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) cout << a[i] << " \n"[i == n];
		else {
			if (a[i] >= a[i - 1] && a[i] % a[i - 1] == 0) {
				a[i]++;
			}
			cout << a[i] << " \n"[i == n];
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}
// x k*x 

// x k*x+1