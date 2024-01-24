#include <bits/stdc++.h>

using namespace std;

void solve() {
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	if(a[0] + a[1] == a[2]) cout << "YES\n";
	else cout << "NO\n";
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin>>_; while(_--)solve();
	return 0;
}