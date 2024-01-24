#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 1; i < n; i ++) {
		if(a[i] == a[i - 1]) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin>>_; while(_--)solve();
	return 0;
}