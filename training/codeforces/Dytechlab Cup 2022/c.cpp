#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
	int x, y;
	bool operator == (const node & B) const {
		return x == B.x && y == B.y;
	}
};
void solve() {
	int n; cin >> n;
	node t[3], mid;
	double a, b;
	int res = -1;
	vector<node> no;
	map<pair<int,int>, int> mp;
	for(int i = 0; i < 3; i ++) {
		int x, y; cin >> x >> y;
		t[i] = {x, y};
		res = max(x + y, res);
		mp[{x, y}] ++;
	}
	int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
	for(int i = 0; i < 3; i ++) {
		int cnt = 0;
		for(int j = 0; j < 4; j ++ ) {
			int x = dx[j] + t[i].x, y = dy[j] + t[i].y;
			if(mp[{x, y}]) cnt ++;
		}
		if(cnt == 2) mid = t[i];
	}

	no.push_back({mid.x - 1, mid.y - 1});
	no.push_back({mid.x - 1, mid.y + 1});
	no.push_back({mid.x + 1, mid.y - 1});
	no.push_back({mid.x + 1, mid.y + 1});
	node f; cin >> f.x >> f.y;
	bool can = true;
	for(auto c : no) if(f == c) {
		can = false;
		cout << "fdddd\n";
	}
	if((f.x - mid.x) % 2 != 0 && (f.y - mid.y) % 2 != 0) can = false;
	if(!can) cout << "NO\n";
	else cout << "YES\n";
}

int main () {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _; cin >> _; while(_ --) solve();
	return 0;
}