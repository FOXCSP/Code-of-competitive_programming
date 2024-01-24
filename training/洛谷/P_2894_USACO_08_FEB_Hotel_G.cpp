#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int  N = 5e4 + 10;
struct Segment_tree {
    int l, r, lz;
    int lmax, rmax, sum, len;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define lmax(x) tree[x].lmax
    #define rmax(x) tree[x].rmax
    #define sum(x) tree[x].sum
    #define len(x) tree[x].len
    #define lz(x) tree[x].lz
} tree[N * 8];

void build(int p, int l, int r) {
    l(p) = l, r(p) = r, lz(p) = 0;
    sum(p) = len(p) = lmax(p) = rmax(p) = r - l + 1;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
}
void pushup(int p) {
    sum(p) = max(max(sum(p<<1), sum(p<<1|1)), rmax(p<<1) + lmax(p<<1|1));
    // p's max left
    if(len(p<<1) == sum(p<<1)) 
        lmax(p) = len(p<<1) + lmax(p<<1|1);
    else 
        lmax(p) = lmax(p<<1);

    // p's max right
    if(len(p<<1|1) == sum(p<<1|1)) 
        rmax(p) = len(p<<1|1) + rmax(p<<1);
    else 
        rmax(p) = rmax(p<<1|1);
}

void pushdown(int p) {
    if(lz(p) == 0) return ;
    
    if(lz(p) == 1) {  // check in
        lmax(p<<1) = rmax(p<<1) = sum(p<<1) = 0;
        lmax(p<<1|1) = rmax(p<<1|1) = sum(p<<1|1) = 0;
        lz(p<<1) = lz(p<<1|1) = 1;
    }
    else if(lz(p) == 2) { // check out
        sum(p<<1) = lmax(p<<1) = rmax(p<<1) = len(p<<1);
        sum(p<<1|1) = rmax(p<<1|1) = lmax(p<<1|1) = len(p<<1|1);
        lz(p<<1) = lz(p<<1|1) = 2;
    }
    lz(p) = 0;
}

void change(int p, int l, int r,int tag) { // check out and check in
    pushdown(p);
    if(l <= l(p) && r >= r(p)) {
        if(tag == 1) // check in
            lmax(p) = rmax(p) = sum(p) = 0;
        if(tag == 2)
            lmax(p) = rmax(p) = sum(p) = len(p);
        lz(p) = tag;
        return ;
    }
    int mid = l(p) + r(p) >> 1;
    if(l <= mid) change(p<<1, l, r, tag);
    if(r > mid) change(p<<1|1, l, r, tag);
    pushup(p);
}

int query(int p, int l, int r, int x) { // query
    if(l == r) return l;
    pushdown(p);
    int mid = l + r >> 1;
    if(sum(p<<1) >= x) return query(p<<1, l, mid, x);
    if(rmax(p<<1) + lmax(p<<1|1) >= x) return mid - rmax(p<<1) + 1;
    if(sum(p<<1|1) >= x) return query(p<<1|1, mid + 1, r, x);
    return 0;
}

int n, m;
void solve() {
    cin >> n >> m;
    build(1, 1, n);
    while(m --) {
        int op;
        cin >> op;
        if(op == 1) {
            int x;
            cin >> x;
            if(sum(1) >= x) {
                int t = query(1, 1, n, x);
                change(1, t, t + x - 1, 1);
                cout << t << "\n";
            }
            else cout << "0\n";
        }
        else {
            int x, y;
            cin >> x >> y;
            change(1, x, x + y - 1, 2);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
