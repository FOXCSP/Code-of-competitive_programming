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
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) / 2;
			if (a[mid] >= (i - mid + 1)) r = mid;
			else l = mid + 1; 
			// 1 4
			// 3
			// 2 a[3] -> (i - mid + 1)
		}
		cout << (i - l + 1) << " ";
	}
	cout << '\n';
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
