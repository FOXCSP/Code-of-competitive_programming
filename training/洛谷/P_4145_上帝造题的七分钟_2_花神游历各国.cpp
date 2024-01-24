#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 1e5+10;
int a[N];
struct Segment_tree {
    int l, r;
    ll sum, maxs;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define maxs(x) tree[x].maxs
} tree[N << 2];

void pushup(int p) {
    sum(p) = sum(p << 1) + sum(p << 1 | 1);
    maxs(p) = max(maxs(p<<1), maxs(p<<1|1));
}

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    if(l == r) { sum(p) = maxs(p) = a[l]; return ;}
    int mid = l + r >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void change(int p, int l, int r) { // make [l, r] squ root
    if(l(p) == r(p)) {
        sum(p) = (ll)sqrt(sum(p));
        maxs(p) = (ll)sqrt(maxs(p));
        return ;
    }
    int mid = l(p) + r(p) >> 1;
    if(l <= mid && maxs(p<<1) > 1) change(p<<1, l, r);
    if(r > mid && maxs(p<<1|1) > 1) change(p<<1|1, l, r);
    pushup(p);
}

ll query(int p, int l, int r) {
    if(l <= l(p) && r >= r(p)) return sum(p);
    int mid = (l(p) + r(p)) >> 1;
    ll val = 0;
    if(l <= mid) val += query(p<<1, l, r);
    if(r > mid) val += query(p<<1|1, l, r);
    return val;
}

inline int read()
{
    int x = 0, w = 1;
    char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar())
        if (ch == '-')
            w = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * w;
}

int n, m;
void solve() {
    n = read();
    for(int i = 1;i <= n; i ++) a[i] = read();
    m = read();
    build(1, 1, n);
    while(m --) {
        int  op, l, r;
        op = read(); l = read(); r = read();
        if(l > r) swap(l, r);
        if(op == 0) {
            change(1, l, r);
        }
        else {
            printf("%lld\n", query(1, l, r));
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
