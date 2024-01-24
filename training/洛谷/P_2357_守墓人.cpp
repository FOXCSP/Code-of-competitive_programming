
#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 200010;

int n, m;

struct Seg {
    int l, r, sum, add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
} tree[N * 8];

void build(int p,int l,int r) {
    l(p) = l, r(p) = r;
    if(l == r) { cin >> sum(p); return ;}
    int mid = l + r >> 1;
    build(p<<1, l, mid), build(p<<1|1, mid + 1, r);
    sum(p) = sum(p<<1) + sum(p<<1|1);
}

void pushdown(int p) {
    if(add(p)) {
        sum(p<<1) += (r(p<<1) - l(p<<1) + 1) * add(p);
        sum(p<<1|1) += (r(p<<1|1) - l(p<<1|1) + 1) * add(p);
        add(p<<1) += add(p);
        add(p<<1|1) += add(p);
        add(p) = 0;
    }
}

void change(int p, int l, int r, int k) {
    pushdown(p);
    if(l <= l(p) && r(p) <= r) {
        sum(p) += (r(p) - l(p) + 1) * k;
        add(p) += k;
        return ;
    }
    int mid = l(p) + r(p) >> 1;
    if(l <= mid) change(p<<1, l, r, k);
    if(r > mid) change(p<<1|1, l, r, k);
    sum(p) = sum(p<<1) + sum(p<<1|1);
}

int query(int p, int l, int r) {
    pushdown(p);
    if(l <= l(p) && r >= r(p)) return sum(p);
    int mid = l(p) + r(p) >> 1;
    int val = 0;
    if(l <= mid) val += query(p<<1, l, r);
    if(r > mid) val +=  query(p<<1|1, l, r);
    return val;
}

void solve() {
    cin >> n >> m;
    build(1, 1, n);
    while(m --) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            change(1, l, r, k);
        }
        if(op == 2) {
            int k; cin >> k;
            change(1, 1, 1, k);
        }
        if(op == 3) {
            int k; cin >> k;
            change(1, 1, 1, -k);
        }
        if(op == 4) {
            int l, r;
            cin >> l >> r;
            cout << query(1, l, r) << "\n";
        }
        if(op == 5) {
            cout << query(1, 1, 1) << '\n';
        }

    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
