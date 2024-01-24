#include <bits/stdc++.h>

using namespace std;

const int N = 110;
vector<int> v[N];
int ind[N], n;
bool st[N];
void topsort() {
	queue<int> q;
	for(int i = 1;i <= n;i ++)
		if(!ind[i]) {
			q.push(i);
			st[i] = 1;
		}
	while(q.size()) {
		int t = q.front(); q.pop();
		cout << t << " ";
		for(auto c : v[t]) {
			if(!st[c] && !(-- ind[c])) {
				st[c] = 1;
				q.push(c);
			}
		}
	}
}

void solve() {
	cin >> n;
	for(int i = 1;i <= n; i ++ ) {
		int x;
		while(cin >> x, x) v[i].push_back(x), ind[x] ++;
	}
	topsort();
}

int main () {
	ios::sync_with_stdio(false),cin.tie(nullptr);
	solve();
	return 0;
}