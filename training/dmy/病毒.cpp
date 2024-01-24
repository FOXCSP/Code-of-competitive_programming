#include <bits/stdc++.h>

using namespace std;

const int N = 30010, M = 2;

struct ACAM {
	int nxt[N][M], fail[N], cnt[N], id[N];
	int qrr[N], t, mark[N];
	int root, idx, malen;
	ACAM() {
		clear();
	}
	void clear() {
		memset(nxt[0], 0, sizeof nxt[0]);
		root = idx = 0;
	}
	int newnode() {
		idx ++; 
		memset(nxt[idx], 0, sizeof nxt[idx]);
		return idx;
	}
	int insert(string s, int tag) {
		malen = max(malen, (int)s.size());
		int len = s.size();
		int now = root;
		for (int i = 0; i < len; i++) {
			int u = s[i] - '0';
			if (!nxt[now][u]) nxt[now][u] = newnode();
			now = nxt[now][u];
		}
		return id[tag] = now;
	}
	void build() {
		fail[root] = root;
		queue<int> q;
		for (int i = 0; i < M; i ++) if (nxt[root][i]) q.push(nxt[root][i]);
		while(q.size()) {
			int u = q.front(); q.pop();
			qrr[t ++] = u;
			for (int i = 0; i < M; i++) {
				if (!nxt[u][i]) {
					nxt[u][i] = nxt[fail[u]][i];
					// 虚空儿子, 给不存在的儿子造一个fail
				}
				else {
					int tmp = nxt[u][i];
					fail[tmp] = nxt[fail[u]][i];
					q.push(tmp);
				}
			}
		}
	}
	vector<vector<int>> dp;
	// 走了i步,当前状态为j
	bool dfs(int u) {
		
	}
} sol; // 注意不能定义在局部变量里面;
int n, m;
string s, x;
void solve() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> x;
		sol.insert(x, i);
	}
	sol.build();
	if (sol.dfs(sol.root)) cout << "NIE\n";
	else cout << "TAK\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
	return 0;
}
