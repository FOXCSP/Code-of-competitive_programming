#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 26;
struct node {
	int nxt[N][M], fail[N], mark[N], id[N], qrr[N];
	int idx, root, t;
	void clear() {
		memset(nxt[0], 0, sizeof nxt[0]);
		idx = root = t = 0;
	}
	int newnode() {
		idx ++;
		memset(nxt[idx], 0, sizeof nxt[idx]);
		return idx;
	}

	int insert(string s, int x) {
		int now = root;
		for (int i = 0; i < s.size(); i ++) {
			int u = s[i] - 'A';
			if (!nxt[now][u]) nxt[now][u] = newnode();
			now = nxt[now][u];
		}
		mark[now] = 1;
		return id[x] = now;
	}

	void build() {
		fail[root] = root;
		queue<int> q;
		qrr[t ++] = root;
		for (int i = 0; i < M; i ++) if (nxt[root][i]) q.push(nxt[root][i]);
		while (q.size()) {
			int now = q.front(); q.pop(); qrr[t ++] = now;
			for (int i = 0; i < M; i ++) {
				if (!nxt[now][i]) nxt[now][i] = nxt[fail[now]][i];
				else {
					int tmp = nxt[now][i];
					fail[tmp] = nxt[fail[now]][i];
					q.push(tmp);
				}
			}
		}
	}
	int dp[10010][N][2];
	void upd(int &x, int y) {
		x += y;
		if (x > 10007) x -= 10007;
	}
	void solve(int m) {
		// 1 将mark向下传
		for (int i = 0; i < t; i ++) {
			mark[qrr[i]] |= mark[fail[qrr[i]]];			
		}

		// 做dp
		dp[0][0][0] = 1;
		for (int i = 0; i < m; i ++) {
			for (int j = 0; j < t; j ++) {
				int u = qrr[j];
				for (int k = 0; k <= 1; k ++) {
					if (dp[i][u][k]) {
						for (int l = 0; l < M; l ++) {
							upd(dp[i + 1][nxt[u][l]][k | mark[nxt[u][l]]],
								dp[i][u][k]);
						}
					}
				}
			}
		}
		int res = 0;
		for (int i = 0; i < t; i ++) {
			// cout << dp[m][i][1] << " \n"[i == M - 1];
			upd(res, dp[m][qrr[i]][1]);
		}
		cout << res << '\n';
	}
} sol;

int n, m;
string s;
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		string x; cin >> x;
		sol.insert(x, i);
	}
	sol.build();
	sol.solve(m);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}

/*
对n个串建acam, 然后拿长度为m的串进行匹配;
所有方案是: 在acam上走m步的所有方案
应该不考虑的方案: 走上m步后包括了完整模式串的方案
如何考虑: 形如a bab, 在匹配ba时, 不会找到完整字串, 但事实是出现了a
故我们考虑将fail链上的所有节点都打上标记

定义dp数组dp[i][j][0/1]表示当前走了i步, 走到了状态j, j没有被标记/被标记
最后累加的答案就是dp[m][?][0]
for 1-m:
	for qrr:
		for k 0/1:
			for x:M:
				dp[i][nxt[j][x]][k|fail[][]]
*/