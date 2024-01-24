#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

int n, m;
const int N = 200010;
int a[N];

struct seg{
    ll val;
    ll lz;
} tr[N * 4];

seg operator + (const seg L, const seg R) {
    return (seg){L.val + R.val, 0};
}

void settag(int p, int lz) {
    tr[p].val ^= lz;
    tr[p].lz ^= lz;
}

void pushdown(int p) {
    if (tr[p].lz) {
        settag(lp, tr[p].lz);
        settag(rp, tr[p].lz);
        tr[p].lz = 0;
    }
}

void pushup(int p) {
    pushdown(p);
    pushdown(lp);
    pushdown(rp);
    tr[p] = tr[lp] + tr[rp];
}

void build(int p, int l, int r) {
    tr[p].lz = 0;
    if (l == r) {
        tr[p].val = a[l];
    } else {
        int mid = (l + r) / 2;
        build(lp, l, mid);
        build(rp, mid + 1, r);
        pushup(p);
    }
}

void debug(int p, int l, int r) {
    if (l == r) {
        // cout << tr[p].val << " ";
    } else {
        pushdown(p);
        int mid = (l + r) / 2;
        debug(lp, l, mid);
        debug(rp, mid + 1, r);
        pushup(p);
    }
}



void modify(int p, int l, int r, int ql, int qr, ll x) {
    pushdown(p);
    if (ql <= l && r <= qr) {
        settag(p, x);
    } else {
        int mid = (l + r) / 2;
        if (ql <= mid) modify(lp, l, mid, ql, qr, x);
        if (qr > mid) modify(rp, mid + 1, r, ql, qr, x);
        pushup(p);
    }
}

ll query(int p, int l, int r, int ql, int qr) {
    pushdown(p);
    if (ql <= l && r <= qr)
        return tr[p].val;
    int mid = (l + r) / 2;
    ll val = 0;
    if (ql <= mid) {
        val += query(lp, l, mid, ql, qr);
    }

    if (qr > mid) {
        val += query(rp, mid + 1, r, ql, qr);
    }
    return val;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int q;
    cin >> q;
    for (; q--; ) {
        int op, l, r;
        ll x;
        cin >> op >> l >> r;
        if (op == 1) {
            // debug(1, 1, n);
            auto ans = query(1, 1, n, l, r);
            cout << ans << '\n';
        } else {
            cin >> x;
            modify(1, 1, n, l, r, x);
        }
    } 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    for (int i = 1; i <= _; i++) {
        solve();
    }
    return 0;
}