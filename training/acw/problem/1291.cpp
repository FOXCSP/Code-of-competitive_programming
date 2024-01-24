#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int a[N], cnt[N], s[N];
void solve() {
	int n;
	cin >> n;
	for(int i = 1;i <= n; i ++) {
		cin >> a[i];
		cnt[a[i]] ++;
	}

	for(int i = 1; i <= N ; i ++)
		for(int j = i; j <= N; j += i)
			s[j] += cnt[i];
	for(int i = 1; i <= n;i ++)
		cout << s[a[i]] - 1 << '\n';
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}