// 维护区间最小值, 区间和
#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 200010;

int n, m, a[N];

struct Seg {
    int l, r, add, sum, mins;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define add(x) tree[x].add
    #define sum(x) tree[x].sum
    #define mins(x) tree[x].mins
} tree[N * 8];

void pushup(int p) {
    sum(p) = sum(p<<1) + sum(p<<1|1);
    mins(p) = min(mins(p<<1), mins(p<<1|1));
}

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    if(l == r) {
        sum(p) = mins(p) = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1, l, mid), build(p<<1|1, mid + 1, r);
    pushup(p);
}

void pushdown(int p) {
    if(add(p)) {
        sum(p<<1) += add(p) * (r(p<<1) - l(p<<1) + 1);
        mins(p<<1) = mins(p<<1) + add(p);

        sum(p<<1|1) += add(p) * (r(p<<1|1) - l(p<<1|1) + 1);
        mins(p<<1|1) = mins(p<<1|1) + add(p);

        add(p<<1|1) += add(p); 
        add(p<<1) += add(p);
        add(p) = 0;
    }
}

void change(int p, int l, int r, int d) {
    pushdown(p);
    if(l <= l(p) && r(p) <= r) {
        sum(p) += d * (r(p) - l(p) + 1);
        mins(p) = mins(p) + d;
        add(p) += d;
        return ;
    }
    int mid = l(p) + r(p) >> 1;
    if(l <= mid) change(p<<1, l, r, d);
    if(r > mid) change(p<<1|1, l, r, d);
    pushup(p);
}

int querysum(int p, int l, int r) {
    pushdown(p);
    if(l <= l(p) && r(p) <= r) {
        return sum(p);
    }
    int mid = l(p) + r(p) >> 1;
    int val = 0;
    if(l <= mid) val += querysum(p<<1, l, r);
    if(r > mid) val += querysum(p<<1|1, l, r);
    return val;
}

int querymin(int p,int l, int r) {
    pushdown(p);
    if(l <= l(p) && r(p) <= r) {
        return mins(p);
    }
    int mid = l(p) + r(p) >> 1;
    int val = 2e18;
    if(l <= mid) val = min(val, querymin(p<<1, l, r));
    if(r > mid) val = min(val, querymin(p<<1|1, l, r));
    return val;
}

void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    build(1, 1, n);
    while(m --) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if(op == 'M') cout << querymin(1, l, r) << '\n';
        else if(op == 'S') cout << querysum(1, l, r) << '\n';
        else {
            int d;
            cin >> d;
            change(1, l, r, d);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
