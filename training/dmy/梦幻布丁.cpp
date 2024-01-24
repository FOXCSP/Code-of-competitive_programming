#include <bits/stdc++.h>

using namespace std;
const int N = 100010, M = 1000010;
int n, m;
int a[M], ans;
vector<int> pos[M];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		pos[a[i]].push_back(i);
	}
	// a[0] …… a[n + 1] ans 多算一次
	for (int i = 1; i <= n + 1; i++) {
		ans += a[i] != a[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		int op;
		scanf("%d", &op);
		if (op == 2) {
			printf("%d\n", ans - 1);
		} else {
			int x, y;
			scanf("%d%d", &x, &y);
			if (x == y) continue;
			if (pos[x].size() > pos[y].size()) {
				pos[x].swap(pos[y]);
			}

			auto modify = [&](int p, int col) {
				ans -= (a[p] != a[p - 1]) + (a[p] != a[p + 1]);
				a[p] = col;
				ans += (a[p] != a[p - 1]) + (a[p] != a[p + 1]);
			};

			if (pos[y].size() == 0) continue;
			int col = a[pos[y][0]]; // 获得pos[y]存的不一定是颜色为y的颜色, 存在和并的过程
			for (auto p : pos[x]) {
				modify(p, col);
				pos[y].push_back(p);
			}
			pos[x].clear();
		}
	}
	return 0;
}