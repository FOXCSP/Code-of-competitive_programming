// 2. 二分 + 二分图判断
// 1. 并查集

#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 20010, M = 100100;
int n, m;
// int p[N], enemy[N];
// struct edge {
//     int a, b, c;
//     bool operator < (const edge & W) const {
//         return c > W.c;
//     }
// };
// vector<edge> e;
// int find(int x) {
//     if(x != p[x]) return p[x] = find(p[x]);
//     return p[x];
// }
// void solve1() {
//     cin >> n >> m;
//     for(int i = 1;i <= n;i ++) p[i] = i;
//     for(int i = 1; i <= m; i ++) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         e.push_back({a, b, c});
//     }
//     sort(e.begin(), e.end());
//     for(auto c : e) {
//         int pa = find(c.a), pb = find(c.b);
//         if(pa != pb) {
//             // 将b加入到a的敌人当中 
//             if(!enemy[c.a]) enemy[c.a] = c.b;
//             else p[pb] = find(enemy[c.a]);
//             // 
//             if(!enemy[c.b]) enemy[c.b] = c.a;
//             else p[pa] = find(enemy[c.b]);
//         }
//         else {
//             cout << c.c << " ";
//             return ;
//         }
//     }
//     cout << "0\n";
// }

int h[N], ne[M], w[M], e[M], idx;

void add(int a,int b,int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int color[N], eg[M];

bool dfs(int mid, int u, int colo) {
	color[u] = colo;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(w[i] <= mid) continue;
		if(!color[j]) {
			if(!dfs(mid, j, 3 - colo)) return false;
		}
		else if(color[j] == colo) return false;
	}
	return true;
}

bool check(int mid) {	
	memset(color, 0, sizeof color);
	for(int i = 1;i <= n;i ++)
		if(!color[i])
			if(!dfs(mid, i, 1))
				return false;
	return true;
}

void solve2() {
	memset(h, -1, sizeof h);
	cin >> n >> m;
	for(int i = 1;i <= m; i ++) {
		int a, b, c; cin >> a >> b >> c;
		add(a, b, c), add(b, a, c);
//		eg[i] = c;
	}
//	sort(eg+1, eg+m+1);
	int l = 1, r = 1e9;
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	// solve1();
	solve2();
	return 0;
}