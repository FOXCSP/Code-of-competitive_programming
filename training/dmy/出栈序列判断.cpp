#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int a[N], n;
void solve() {
	cin >> n;
	int now = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		while (now <= a[i]) {
			cout << "push " << now << '\n';
			now ++;
		}
		if (now > a[i]) {
			cout << "pop\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}