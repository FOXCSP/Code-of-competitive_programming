#include <bits/stdc++.h>

using namespace std;

const int N = 110;
vector<int> e[N];
int n, m;
int p[N];
int find(int x) {
	if (x != p[x]) return p[x] = find(p[x]);
	else return x;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	int cnt = n;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		int pu = find(u);
		int pv = find(v);
		if (pu != pv) {
			p[pu] = pv;
			cnt--;
		}
	}
	cout << cnt <<'\n';
	return 0;
}