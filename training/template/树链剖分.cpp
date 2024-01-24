// https://atcoder.jp/contests/abc294/submissions/40348236
#include <bits/stdc++.h>
#define fi first
#define se second 
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout<<fixed<<setprecision(12);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--
// 树链剖分

const int N = 200010;
int n, m, a[N];
int dep[N], l[N], r[N], top[N], id[N], e_to_p[N];
int son[N], sz[N], fa[N], tot, p_to_e[N];

// l[x], r[x]求出的是第x个点在dfs序上的区间范围
// e_to_p[x] 求的是第x条边依附于哪个点
// p_to_e[x] 求的是第x个点的边是哪个

vec<P(int)> e[N];


void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    son[u] = -1;
    sz[u] = 1;
    for (auto [v, p]: e[u]) {
        if (v == f) continue;
        dfs1(v, u);
        e_to_p[p] = v;
        p_to_e[v] = p;
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v]) {
            son[u] = v;
        }
    }
}

void dfs2(int u, int t) {
    top[u] = t;
    l[u] = ++tot;
    id[tot] = u;
    if (son[u] != -1) {
        dfs2(son[u], t);
    }
    for (auto [v, p]: e[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
    r[u] = tot;
}

struct seg{
    ll sum;
    seg operator + (const seg& R) const {
        return (seg){sum + R.sum};
    }
    seg operator - (const seg& R) const {
        return (seg){sum - R.sum};
    }
} tr[N << 4];


void pushup(int p) {
    tr[p] = tr[lp] + tr[rp];
}

void build(int p, int l, int r) {
    if (l == r) {
        tr[p] = {1ll * a[p_to_e[id[l]]]};
    } else {
        int mid = (l + r) / 2;
        build(lp, l, mid);
        build(rp, mid + 1, r);
        pushup(p);
    }
}

void modify(int p, int l, int r, int pos, ll d) {
    if (l == r) {
        tr[p].sum = d;
    } else {
        int mid = (l + r) / 2;
        if (pos <= mid) modify(lp, l, mid, pos, d);
        else modify(rp, mid + 1, r, pos, d);
        pushup(p);
    }
}

seg query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tr[p];
    int mid = (l + r)/2;
    if (ql > mid) return query(rp, mid + 1, r, ql, qr);
    else if (qr <= mid) return query(lp, l, mid, ql, qr);
    else return query(lp, l, mid, ql, qr) + query(rp, mid + 1, r, ql, qr);
}

seg query(int u, int v) {
    seg ans = {0};
    int p = u, q = v;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
            if (u != v) ans = ans + query(1, 1, n, l[top[v]], l[v]);
            v = fa[top[v]];
        } else {
            if (u != v) ans = ans + query(1, 1, n, l[top[u]], l[u]);
            u = fa[top[u]];
        }
    }
    if (v == u) return ans;

    // !!!! 
    if (dep[v] < dep[u]) {
        ans = ans + query(1, 1, n, l[v]+1, l[u]);
    } else {
        ans = ans + query(1, 1, n, l[u]+1, l[v]);
    }
    return ans;
}

void solve(int caseT = 1) {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].pb({v, i});
        e[v].pb({u, i});
        a[i] = w;
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            modify(1, 1, n, l[e_to_p[x]], y);
        } else {
            seg ans = query(x, y);
            cout << ans.sum << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _=1;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}