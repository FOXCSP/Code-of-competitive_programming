#include <bits/stdc++.h>
#define fi first
#define se second
#define sf scanf
#define pf printf
#define inf 0x3f3f3f3f
//#define int long long
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
//
LL gcd(LL x,LL y) {return !y ? x:gcd(y, x%y);}
LL qmi(LL a,LL b) {LL res=1; while(b) {if(b&1)res=res*a;a=a*a,b>>=1;}return res;}

/*--code --*/
const int N = 2010;
char g[N][N];
int n, m, dist[N][N], ans = 0;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
void bfs() {
	queue<PII> q;
    memset(dist, -1, sizeof dist);
	q.push({1, 1});
    dist[1][1] = 0;
	while(q.size()) {
		auto t = q.front(); q.pop();
		int x = t.fi, y = t.se;
		for(int i = 0;i < 4;i ++) {
			int a = x + dx[i], b = y + dy[i];
			if(a >=1 && a <= n && b >= 1 && b <= m && g[a][b] != '#') {
				int dt = (g[a][b] == '.' ? 1 : 0);
				if(dist[a][b] == -1 || d + dt < dist[a][b]) {
					dist[a][b] = d+dt;
					q.push({dist[a][b], {a, b}});
				}
			}
		}
	}
	ans = dist[n][m];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;

	for(int i = 1;i <= n;i ++)
		cin >> g[i]+1;
	// for(int i = 1;i <= n;i ++)
	// 	pf("%s\n", g[i]+1);
	bfs();
    cout << ans << endl;
    return 0;
}
