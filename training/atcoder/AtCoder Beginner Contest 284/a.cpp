#include <bits/stdc++.h>

using namespace std;

int main() {
	int n; cin >> n;
	vector<string> v;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		v.push_back(s);
	}
	int l = v.size();
	for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << '\n';
	return 0;
}