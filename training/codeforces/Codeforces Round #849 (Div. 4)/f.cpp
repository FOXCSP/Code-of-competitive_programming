#include <bits/stdc++.h>
#define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 200010;

int n, q;
ll a[N];

struct info {
    ll val;
};

info operator + (const info L, const info R) {
    return info {L.val + R.val};
}

struct seg {
    info val;
    ll tag, l, r;
} tr[N * 8];

void pushup(int p) {
    tr[p].val = tr[lp].val + tr[rp].val;
}

void settag(int p, ll t) {
    ll len = tr[p].r - tr[p].l + 1;
    tr[p].val.val += t * (len);
    tr[p].tag += t;
}

void pushdown(int p) {
    if (tr[p].tag) {
        settag(lp, tr[p].tag);
        settag(rp, tr[p].tag);
        tr[p].tag = 0;
    }
}

void build(int p, int l, int r) {
    tr[p].l = l;
    tr[p].r = r;
    tr[p].tag = 0;
    tr[p].val.val = 0;
    if (l == r) {
        tr[p].val = {0};
        tr[p].tag = 0;
    } else {
        int mid = (l + r) / 2;
        build(lp, l, mid);
        build(rp, mid + 1, r);
        pushup(p);
    }
}

ll query(int p, int l, int r, int x) {
    if (l == r) {
        return tr[p].val.val;
    }
    pushdown(p);
    int mid = (l + r) / 2;
    if (x <= mid) return query(lp, l, mid, x);
    else return query(rp, mid + 1, r, x);
}

void modify(int p, int l, int r, int L, int R, int d) {
    if (l > R || r < L) return ;
    if (L <= l && r <= R) {
        settag(p, d);
        pushdown(p);
        return ;
    }
    pushdown(p);
    int mid = (l + r) / 2;
    if (L <= mid) modify(lp, l, mid, L, R, d);
    if (R > mid) modify(rp, mid + 1, r, L, R, d);
    pushup(p);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int op, l, r, x;
        cin >> op;
        if (op == 1) {
            cin >> l >> r;
            modify(1, 1, n, l, r, 1);
        } else {
            cin >> x;
            ll t = query(1, 1, n, x);
            ll ans = a[x];
            while (t > 0) {
                if (ans < 10) break;
                ll res = ans;
                ll ress = 0;
                while (res) {
                    ress += res % 10;
                    res /= 10;
                }
                ans = ress;
                t--;
            }
            cout << ans << '\n';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
