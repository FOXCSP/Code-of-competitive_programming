#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, m;
void solve() {
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n, 0));
	if (n & 1) {
		int a = (n*n+1)/2;
		int b = a + 1;
		int i = 0, j = 0, turn = 1;
		int dx[] = {0, 1, -1, -1, 1}, dy[] = {0, -1, -1, 1, 1};
		for (int k = 1; k <= n * n; k++) {
			if (!(i >= 0 && i < n && j >= 0 && j < n) || g[i][j]) {
				i += dx[turn], j += dy[turn];
				turn++;
				turn %= 5;
				if (turn == 0) turn = 1;
			}
			if (k&1) g[i][j] = a--;
			else g[i][j] = b++;
			if (turn == 1) j++;
			if (turn == 2) i++;
			if (turn == 3) j--;
			if (turn == 4) i--;
		}
	} else {
		int a = n*n/2, b = n*n/2+1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((j+1)&1) g[i][j] = a--;
				else g[i][j] = b++;
			}
		}
		for (int i = 1; i < n; i += 2) 
			reverse(g[i].begin(), g[i].end());
	}
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) cout << g[i][j] << " \n"[j == n - 1];
}

int main() {
	int _; cin >> _;
	while (_--) solve();
	return 0;
}