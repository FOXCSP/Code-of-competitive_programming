#include <bits/stdc++.h>

using namespace std;

const int N = 110;
int a[N];
void solve() {
	int n; cin >> n;
	cout << n << '\n';
	for(int i = 1;i <= n;i ++) {
		a[i] = i;
		cout << a[i] << " \n"[i == n];
	}
	for(int i = 2; i <= n; i ++) {
		swap(a[i], a[i - 1]);
		for(int j = 1;j <= n;j ++) cout << a[j] << " \n"[j == n];
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T; while(T --) solve();
	return 0;
}