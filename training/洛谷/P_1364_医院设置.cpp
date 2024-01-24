#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define pb push_back
#define rp (p<<1|1)
#define lp (p<<1)
#define endl '\n'
#define fi first
#define se second
// #define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 110, M = N * 2;
int n, m;

int h[N], w[M], e[M], ne[M], idx;
void add(int a,int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u, int dep, int fa) {
    int res = 0;
    for(int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        int t = 0;
        if(fa != j) res += dfs(j, dep + 1, u);
    }
    res += w[u] * dep;
    // if(u == 3) cout << res << " res\n";
    return res;
}

void solve() {
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1;i <= n;i ++) {
        int a, b, c;
        cin >> c >> a >> b;
        if(a) add(i, a), add(a, i);
        if(b) add(i, b), add(b, i);
        w[i] = c;
    }
    int ans = 2e9;
    // ans = dfs(1, 0, -1);
    for(int i = 1;i <= n; i ++)
        ans = min(ans, dfs(i, 0, -1));
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
