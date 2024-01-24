#include <bits/stdc++.h>

using namespace std;

void solve() {
	string a = "", b = "";
	cin >> a >> b;
	int n = b.size();
	int m = a.size();
	if(m - 1 < n && b.substr(0, m) == a) cout << "Yes\n";
	else cout << "No\n";
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}