#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

const int N = 1e5+10;

struct Segment_tree {
    int l, r;
    ll sum, add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
} tree[N*4];
int a[N], n, m;

void build(int p, int l, int r) {
    l(p) = l, r(p) = r;
    if(l == r) { sum(p) = a[l]; return ;}
    int mid = (l + r) >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid+1, r);
    sum(p) = sum(p<<1) + sum(p<<1|1);
}

void spread(int p) {
    if(add(p)) {
        sum(p<<1) += add(p)*(r(p<<1) - l(p<<1) + 1);
        sum(p<<1|1) += add(p)*(r(p<<1|1) - l(p<<1|1) + 1);
        add(p<<1) += add(p);
        add(p<<1|1) += add(p);
        add(p) = 0;       
    }
}

void change(int p, int l, int r, int d) {
    if(l <= l(p) && r >= r(p)) {
        // 完全覆盖
        sum(p) += (ll)d * (r(p) - l(p) + 1);
        add(p) += d;
        return ;
    }
    spread(p);
    int mid = (l(p) + r(p)) >> 1;
    if(l <= mid) change(p<<1, l, r ,d);
    if(r > mid) change(p<<1|1, l, r, d);
    sum(p) = sum(p<<1) + sum(p<<1|1);
}
ll ask(int p, int l,int r) {
    if(l <= l(p) && r >= r(p)) return sum(p);
    spread(p);
    int mid = (l(p) + r(p)) >> 1;
    ll val = 0;
    if(l <= mid) val += ask(p<<1, l, r);
    if(r > mid) val += ask(p<<1|1,l ,r);
    return val;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    std::cin >> n >> m;
    for(int i = 1;i <= n;i ++) std::cin >> a[i];
    build(1, 1, n);
    while(m --) {
        string op;
        int l, r;
        std::cin >> op >> l >> r;
        if(op == "Q") {
            // std::cout << 1 << endl;
            std::cout << ask(1, l, r) << endl;
        }
        else {
            int d;
            std::cin >> d;
            change(1, l, r, d);
        }
    }
    return 0;
}
