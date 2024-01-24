#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e5 + 10;
int a[N], n, m, mod; 
struct Segment_tree {
    int l, r, lz;
    ll sum, mul, add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define lz(x) tree[x].lz
    #define sum(x) tree[x].sum
    #define mul(x) tree[x].mul
    #define add(x) tree[x].add
}tree[N*4];

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    add(p) = 0, mul(p) = 1; 
    if(l == r) { sum(p) = a[l]; return ;}
    int mid = l + r >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    sum(p) = sum(p<<1) % mod + sum(p<<1|1) % mod;
}

void spreed(int p) {
    sum(p<<1) = (sum(p<<1) * mul(p) + (r(p<<1) - l(p<<1) + 1) * add(p)) % mod;
    sum(p<<1|1) = (sum(p<<1|1) * mul(p) + (r(p<<1|1) - l(p<<1|1) + 1) * add(p)) % mod;
    mul(p<<1) = (mul(p<<1) * mul(p)) % mod;
    mul(p<<1|1) = (mul(p<<1|1) * mul(p)) % mod; 
    add(p<<1) = (add(p<<1) * mul(p) + add(p)) % mod;
    add(p<<1|1) = add(p<<1|1) * mul(p) + add(p) % mod;
    add(p) = 0;
    mul(p) = 1;
}

void change1(int p, int l, int r, int d) { // add
    if(l <= l(p) && r >= r(p)) {
        sum(p) = (sum(p) + (r(p) - l(p) + 1) * d) % mod;
        add(p) = (add(p) + d)% mod;
        return ;
    }
    spreed(p);
    int mid = (l(p) + r(p)) >> 1;
    if(l <= mid ) change1(p<<1, l, r, d);
    if(r > mid ) change1(p<<1|1, l, r, d);
    sum(p) = (sum(p<<1) + sum(p<<1|1)) % mod;
}

void change2(int p, int l, int r, int x) { // mul
    if(l <= l(p) && r >= r(p)) {
        add(p) = (add(p) * x) % mod;
        sum(p) = (sum(p) * x) % mod;
        mul(p) = (mul(p) * x) % mod;
        return ;
    }
    spreed(p);
    int mid = (l(p) + r(p)) >> 1;
    if(l <= mid ) change2(p<<1, l, r, x);
    if(r > mid ) change2(p<<1|1, l, r, x);
    sum(p) = (sum(p<<1) + sum(p<<1|1)) % mod;
}

ll ask(int p, int l, int r) {
    if(l <= l(p) && r >= r(p)) {
        return sum(p);
    }
    spreed(p);
    int mid = (l(p) + r(p)) >> 1;
    ll val = 0;
    if(l <= mid) val = (val %mod + ask(p<<1, l ,r)) % mod;
    if(mid < r) val = (val %mod + ask(p<<1|1, l, r)) % mod;
    return val % mod;
}

void solve() {
    cin >> n >> m;
    mod = 1e18;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    build(1, 1, n);
    while(m --) {
        int op, x, y, k;
        cin >> op >> x >> y;
        if(op == 1) {
            cin >> k;
            change1(1, x, y, k);
        }
        else {
            cout << ask(1, x, y) << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
