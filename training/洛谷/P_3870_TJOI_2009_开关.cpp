#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010;
int a[N], n, m;

struct Seg {
    int l, r, sum, lz;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define lz(x) tree[x].lz
} tree[N * 4];

void pushup(int p) {
    sum(p) = sum(p<<1) + sum(p<<1|1);
}

void pushdown(int p) {
    if(lz(p)) {
        sum(p<<1) = (r(p<<1) - l(p<<1) + 1) - sum(p<<1);
        sum(p<<1|1) = (r(p<<1|1) - l(p<<1|1) + 1) - sum(p<<1|1);
        lz(p<<1) ^= 1;
        lz(p<<1|1) ^= 1;
        lz(p) = 0;
    }
}

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    if(l == r) { sum(p) = 0; return ;}
    int mid = l + r >> 1;
    build(p<<1, l, mid), build(p<<1|1, mid + 1, r);
    pushup(p);
}

void change(int p, int l, int r) {
    pushdown(p);
    if(l <= l(p) && r >= r(p)) {
        sum(p) = r(p) - l(p) + 1 - sum(p);
        lz(p) ^= 1;
        return ;
    }
    int mid = l(p) + r(p) >> 1;
    if(l <= mid) change(p<<1, l, r);
    if(r > mid) change(p<<1|1, l, r);
    pushup(p);
}

int query(int p, int l, int r) {
    pushdown(p);
    if(l <= l(p) && r >= r(p)) return sum(p);
    int mid = l(p) + r(p) >> 1;
    int val = 0;
    if(l <= mid) val += query(p<<1, l, r);
    if(r > mid) val += query(p<<1|1, l, r);
    return val;
}


void solve() {
    cin >> n >> m;
    build(1, 1, n);
    while(m --) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op) cout << query(1, l, r) << '\n';
        else change(1, l, r);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
