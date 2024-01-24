#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
#define P(T) pair<T, T> 
#define vec vector
#define fi first
#define se second
#define pb push_back
#define all(T) T.begin(), T.end()
using namespace std;
typedef long long ll;
const int N = 100010;
const ll mod = 1000000007;

int n, m;
int t[1000010], d[1000010], fa[1000010][20];

int lca(int a, int b){
	if (d[a] < d[b]) swap(a, b);
	for (int i = 19; i >= 0; i--)
		if (d[fa[a][i]] >= d[b])
			a = fa[a][i];
	if (a == b) return a;
	for (int i = 19; i >= 0; i--)
		if (fa[a][i] != fa[b][i]) {
			a = fa[a][i];
			b = fa[b][i];
		}
	return fa[a][0];
} 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> m;
	int n = 4;
	int s, t;
	s = 2, t = 3;
	int len = 2;
	d[2] = d[3] = d[4] = 1;
	fa[2][0] = fa[3][0] = fa[4][0] = 1;
	for (; m--; ) {
		int u;
		cin >> u;
		int x = ++n;
		int y = ++n;
		d[x] = d[u] + 1;
		d[y] = d[u] + 1;
		fa[x][0] = u;
		fa[y][0] = u;
		for (int i = 1; i < 20; i++) {
			fa[x][i] = fa[fa[x][i - 1]][i - 1];
			fa[y][i] = fa[fa[y][i - 1]][i - 1];
		}
		
		int t1 = lca(s, x);
		int t2 = lca(t, x);
//		cout << x << " " << s << " " << t1 << '\n';
//		cout << x << " " << t << " " << t2 << '\n';
		int d1 = d[x] + d[s] - 2 * d[t1];
		int d2 = d[x] + d[t] - 2 * d[t2];
		
		int ns = s, nt = t;
		if (d1 > len) 
			len = d1, ns = s, nt = x;
		
		if (d2 > len)
			len = d2, ns = t, nt = x;
		cout << len << '\n';
		swap(ns, s);
		swap(nt, t);
//		cout << " new bd: " << s << " " << t <<'\n';
	}
	return 0;
}
