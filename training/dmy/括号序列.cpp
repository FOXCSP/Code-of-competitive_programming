#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
void solve() {
	cin >> n;
	string s; cin >> s;
	string stk;
	for (auto c : s) {
		if (!stk.size() || c == '(' || c == '[') {
			stk.push_back(c);
			continue;
		}
		if (c == ')' && stk.back() == '(') stk.pop_back();
		else if (c == ']' && stk.back() == '[') stk.pop_back();
		else {
			cout << "No\n";
			return ;
		}
	}
	if (stk.size()) cout << "No\n";
	else cout << "Yes\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}