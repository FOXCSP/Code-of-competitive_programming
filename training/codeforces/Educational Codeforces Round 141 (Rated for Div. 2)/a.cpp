#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N], b[N];
void solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1, j = n, k = 1; i <= j; i++, j--) {
		b[k++] = a[i];
		if (i != j) b[k++] = a[j];
	}
	for (int i = 1; i <= n; i++) {
		a[i] = a[i - 1] + b[i];
		if (b[i] == a[i - 1]) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n;i++) cout << b[i] << " \n"[i == n];
}

int main() {
	int _; cin >> _;
	while (_--) solve();
	return 0;
}