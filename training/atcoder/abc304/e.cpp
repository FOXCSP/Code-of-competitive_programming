#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

const int N = 200010;
int p[N], n, m;

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		int pu = find(u);
		int pv = find(v);
		if (pu != pv) p[pv] = pu;
	}
	int k;
	cin >> k;
	map<pair<int, int>, int> mp; 
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		int px = find(x);
		int py = find(y);
		if (px > py) swap(px, py);
		mp[{px, py}]++; 
	}
	
	int q;
	cin >> q;
	for (; q--; ) {
		int x, y;
		cin >> x >> y;
		int px = find(x);
		int py = find(y);
		if (px > py) swap(px, py); 
		if (mp.count({px, py}) == 0) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	
	return 0;
} 
