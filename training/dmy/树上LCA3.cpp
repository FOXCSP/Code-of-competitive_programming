#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unsigned int A, B, C;
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}

const int N = 500010, LOGN = 20;
pair<int, int> f[LOGN + 2][N * 2]; //
int dep[N], id[N], tot, lg[N * 2], n, m;
vector<int> e[N];
ll ans;

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	f[0][++tot] = {dep[u], u};
	id[u] = tot;
	for (auto v : e[u]) {
		if (v == fa) continue;
		dfs(v, u);
		f[0][++tot] = {dep[u], u};
	}
}

int main(){
    scanf("%d%d%u%u%u", &n, &m, &A, &B, &C);
    // 输入树边
    for (int i = 1; i < n; i++) {
    	int u, v;
    	scanf("%d%d", &u, &v);
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    dfs(1, 0);
    lg[1] = 0;
    for (int i = 2; i <= tot + 1; i++) lg[i] = lg[i / 2] + 1;
    for (int j = 1; j <= LOGN; j++) {
    	for (int i = 1; i + (1 << j) - 1 <= tot; i++) {
    		f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
    	}
	}
    for (int i = 1; i <= m; i++) {
        unsigned int u = rng61() % n + 1, v = rng61() % n + 1;
        int l = id[u], r = id[v];
        if (l > r) swap(l, r);
        int k = lg[r - l + 1];
        int t = min(f[k][l], f[k][r - (1 << k) + 1]).second;
        ans ^= 1ll * t * i;
    }
    printf("%lld\n", ans);
    return 0;
}