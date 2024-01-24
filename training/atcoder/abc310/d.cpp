#include <bits/stdc++.h>
#define pb push_back
#define SZ(T) (int)(T.size())
#define fi first
#define se second
using namespace std;
typedef long long ll;

const int N = 50;
const ll mod = 998244353;

int n, t, m, ans;
bool no[N][N], st[N];
vector<int> vx;
void dfs(int now, int rem) {
	if (now > rem) {
		return ;
	}
	if (now == 0 && rem == 0) {
		ans++;
		return ;
	}
	
	if (rem >= now) {
		for (int i = 1; i <= n; i++)
			if (!st[i]) {
				if (rem == now) {
					st[i] = 1;
					dfs(now - 1, rem - 1);
					st[i] = 0;
				}
				
				if (rem > now) {
					st[i] = 1;
				 	vx.pb(i);
					dfs(now, rem - 1);
				}
			}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> t >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		no[x][y] = 1;
		no[y][x] = 1;
	}
	
	dfs(t, n);
	cout << ans << '\n';
	return 0;
}
