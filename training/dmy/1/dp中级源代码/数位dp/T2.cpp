#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int vis[11];
vector<int> d;
int n, k;

bool dfs(int x, bool larger, int cnt, int num) { // 搜到了第x位，前x位是不是大于n的前x位，前x位有多少种不同的数字。
	if (x == d.size()) {
		printf("%d\n", num);
		return true;
	} else {
		for (int i = larger ? 0 : d[x]; i <= 9; i++) {
			vis[i] += 1;
			int ncnt = cnt;
			if (vis[i] == 1) ncnt += 1;
			if (ncnt <= k && dfs(x + 1, larger | (i > d[x]), ncnt, num * 10 + i)) {
				return true;
			}
			vis[i] -= 1;
		}
		return false;
	}
}

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i <= 9; i++) vis[i] = 0;
	d.clear();
	while (n) {
		d.push_back(n % 10);
		n /= 10;
	}
	reverse(d.begin(), d.end());
	dfs(0, 0, 0, 0); // 当前的前缀有没有大于n的前缀
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int i = 0; i < tc; i++) {
		solve();
	}
}