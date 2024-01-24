#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
int n, k;
int a[N];
void solve() {
	cin >> n >> k;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(a[k + 1] == a[k]) cout << "-1\n";
	else {
		if(a[k] == 0 && a[k] < a[1] - 1) a[k] ++;
		cout << (a[k] ? a[k] : -1) << '\n';
	}
}


int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}