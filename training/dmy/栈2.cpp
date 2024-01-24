#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
int stk[N], top;
void solve() {
	int m; cin >> m;
	while (m --) {
		string s; cin >> s;
		if (s == "push") {
			int x; cin >> x;
			stk[++ top] = x; 
		} else if (s == "query") {
			int x; cin >> x;
			cout << stk[top - x + 1] << '\n';
		} else {
			top --;
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}