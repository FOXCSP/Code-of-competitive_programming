#include <bits/stdc++.h>

using namespace std;

int n; string s;
void solve() {
	cin >> n >> s;
	string que;
	for (char c : s) {
		if (!que.size()) que.push_back(c);
		else {
			if (que.back() == c) que.pop_back();
			else que.push_back(c);
		}
	}
	cout << que << '\n';
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	solve();
	return 0;
}