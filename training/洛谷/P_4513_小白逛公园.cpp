#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 500010;
int n, m, a[N];
struct Segment_tree {
    int l, r;
    int msum, lmax, rmax, lz, sum;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define lmax(x) tree[x].lmax
    #define rmax(x) tree[x].rmax
    #define msum(x) tree[x].msum
} tree[N * 4];

void pushup(int p) {
    lmax(p) = max(lmax(p<<1), msum(p<<1) + lmax(p<<1|1));
    rmax(p) = max(rmax(p<<1|1), rmax(p<<1) + msum(p<<1|1));
    sum(p) = max({sum(p<<1), sum(p<<1|1), rmax(p<<1) + lmax(p<<1|1)});
    msum(p) = msum(p<<1) + msum(p<<1|1);
}

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    if(l == r) {
        msum(p) = sum(p) = lmax(p) = rmax(p) = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void change (int p, int x, int y) {
    // pushdown(p);
    if(l(p) == r(p)) {
        msum(p) = sum(p) = lmax(p) = rmax(p) = y;
        return ;
    }
    int mid = l(p) + r(p) >> 1;
    if(x <= mid) change(p<<1, x, y);
    if(x > mid) change(p<<1|1, x, y);
    pushup(p);
}

Segment_tree query(int p, int l, int r) {
    if(l <= l(p) && r >= r(p)) return tree[p];
    int mid = l(p) + r(p) >> 1;
    if(l > mid) return query(p<<1|1, l, r);
    if(r <= mid) return query(p<<1, l, r);
    else {
        Segment_tree res1 = query(p<<1, l, r), res2 = query(p<<1|1, l, r), ret;
        ret.sum = max({res1.sum, res2.sum, res1.rmax + res2.lmax});
        ret.lmax = max(res1.lmax, res1.msum + res2.lmax);
        ret.rmax = max(res2.rmax, res2.msum + res1.rmax);
        ret.msum = res1.msum + res2.msum;
        return ret;
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while(m --) {
        int op, a, b;
        cin >> op >> a >> b;
        if(op == 1) {
            if(a > b) swap(a, b);
            cout << query(1, a, b).sum << "\n";
        }
        else {
            change(1, a, b);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
