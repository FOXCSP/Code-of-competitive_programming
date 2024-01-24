#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double lbd;
// head

const int N = 400010;
int a[N], n, m, tot;
int L[N], R[N], id[N];
vec<int> e[N];

void dfs(int u, int f) {
    L[u] = ++tot;
    id[tot] = u;
    for (auto v : e[u]) {
        if (v != f)
            dfs(v, u);
    }
    R[u] = tot;
}

struct seg {
    int tg;
    ll col;
} tr[N * 6];


void pushup(int p) {
    tr[p].col = tr[lp].col | tr[rp].col;
}

void settag(int p, int c) {
    tr[p].col = 0;
    tr[p].col |= (1ll << c);
    tr[p].tg = c;
}

void pushdown(int p) {
    if (tr[p].tg) {
        settag(lp, tr[p].tg);
        settag(rp, tr[p].tg);
        tr[p].tg = 0;
    }
}

void build(int p, int l, int r) {
    if (l == r) {
        tr[p].col = (1ll << a[id[l]]);
    } else {
        int mid = (l + r) / 2;
        build(lp, l, mid);
        build(rp, mid + 1, r);
        pushup(p);
    }
}

void modify(int p, int l, int r, int ql, int qr, int c) {
    pushdown(p);
    if (ql <= l && r <= qr) {
        settag(p, c);
    } else {
        int mid = (l + r) / 2;
        if (ql <= mid) modify(lp, l, mid, ql, qr, c);
        if (qr > mid) modify(rp, mid + 1, r, ql, qr, c);
        pushup(p);  
    }
}

seg query(int p, int l, int r, int ql, int qr) {
    pushdown(p);
    if (ql <= l && r <= qr) return tr[p];
    int mid = (l + r) / 2;
    if (ql > mid) return query(rp, mid + 1, r, ql, qr);
    else if (qr <= mid) return query(lp, l, mid, ql, qr);
    else {
        auto res1 = query(lp, l, mid, ql, qr);
        auto res2 = query(rp, mid + 1, r, ql, qr);
        res1.col |= res2.col;
        return res1;
    }
}


void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(1, 0);

    // for (int i = 1; i <= n; i++)
    //     cout << L[i] << " " << R[i] << "\n";
    
    build(1, 1, tot);
    for (; m--; ) {
        int op, u, c;
        cin >> op;
        if (op == 1) {
            cin >> u >> c;
            modify(1, 1, n, L[u], R[u], c);
        } else {
            cin >> u;
            auto ans = query(1, 1, n, L[u], R[u]);
            int cnt = 0;
            for (; ans.col; ans.col /= 2) {
                cnt += (ans.col & 1);
            }
            cout << cnt << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int _;
    _=1;
    // cin>>_;
    for (int i = 1; i <= _; i++)
        solve(i);
    return 0;
}