#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
bool check(char a, char b) {
	return (a - b == 32) || (b - a == 32); 
}
void solve() {
	string que, s;
	int n;
	cin >> n >> s;
	for (char c : s) {
		if (!que.size()) que.push_back(c);
		else {
			if (check(c, que.back())) que.pop_back();
			else que.push_back(c);
		}
	}
	cout << que << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	solve();
	return 0;
}