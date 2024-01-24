#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 200010;

int a[N], n, m;

struct Seg {
    int l, r, maxx;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define maxx(x) tree[x].maxx
} tree[N * 4];

void build(int p,int l,int r) {
    l(p) = l, r(p) = r;
    if(l == r) { maxx(p) = a[l]; return ;}
    int mid = l + r >> 1;
    build(p<<1, l, mid), build(p<<1|1, mid + 1, r);
    maxx(p) = max(maxx(p<<1), maxx(p<<1|1));
}

void change(int p,int x, int y) {
    if(l(p) == r(p)) {
        maxx(p) = y;
        return ;
    }
    int mid = l(p) + r(p) >> 1;
    if(x > mid) change(p<<1|1, x, y);
    if(x <= mid) change(p<<1, x, y);
    maxx(p) = max(maxx(p<<1), maxx(p<<1|1));
}

int query(int p, int l, int r) {
    if(l <= l(p) && r >= r(p)) return maxx(p);
    int mid = l(p) + r(p) >> 1;
    int val = 0;
    if(l <= mid) val = max(val, query(p<<1, l, r));
    if(r > mid) val = max(val, query(p<<1|1, l, r));
    return val;
}

void solve() {
    cin >> n >> m;
    for(int i  =1;i <= n ;i ++) cin >> a[i];
    build(1, 1, n);
    while(m --) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if(op == 'Q') cout << query(1, x, y) << "\n";
        else if(op == 'U' && a[x] < y) change(1, x, y), a[x] = y;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
