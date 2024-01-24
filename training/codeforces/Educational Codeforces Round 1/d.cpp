#include <bits/stdc++.h>
#define fi first
#define se second
#define db double
#define lp (p<<1)
#define rp (p<<1|1)
#define vec vector
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define setdb cout<<fixed<<setprecision(12);
using namespace std;
typedef long long ll;
ll qmi(ll a, ll b, ll mod)
{ll res=1; while(b) { if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;} return res;}
/* -- head -- */
int n, m, k;
char g[1010][1010];
int ans[100010];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool st[1010][1010];
void solve(int Tcase = 1) {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> g[i] + 1;
	}
	map<P(int), int> mp;
	int id = 1;
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		if (g[x][y] == '*') {
			cout << 0 << '\n';
		} else {
			int tg = mp[{x, y}];
			if (tg == 0) {
				if (st[x][y] == 0) {
					tg = ++id;
					int cur = 0;
					queue<P(int)> que;
					mp[{x, y}] = tg;
					que.push({x, y});
					st[x][y] = 1; 
					while (!que.empty()) {
						auto p = que.front();
						que.pop();
						int px = p.fi, py = p.se;
						mp[{px, py}] = tg;
						int res = 0;
						for (int j = 0; j < 4; j++) {
							int nx = px + dx[j];
							int ny = py + dy[j];
							if (nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny]) continue;
							if (g[nx][ny] == '*') res++;
							else {st[nx][ny] = 1; que.push({nx, ny});}
						}
						cur += res;
					}
					ans[tg] = cur;
				}
			}
			cout << ans[tg] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int _; 
	_=1;
	for (int i = 1; i <= _; i++) solve(i);
	return 0;
}
