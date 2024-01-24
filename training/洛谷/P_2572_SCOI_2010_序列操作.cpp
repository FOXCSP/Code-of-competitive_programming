#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

#define rp p<<1|1
#define lp p<<1

const int N = 200010;
int n, m;
int a[N];
struct Segment_tree {
    int l, r;
    int lmax0, rmax0;
    int lmax1, rmax1;
    int sum, lz, csum0, csum1, rev; 
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define lmax0(x) tree[x].lmax0 // 左端点最大连续0
    #define rmax0(x) tree[x].rmax0 // 右端点最大连续0
    #define lmax1(x) tree[x].lmax1 // 左端点最大连续1
    #define rmax1(x) tree[x].rmax1 // 右端点最大连续1
    #define sum(x) tree[x].sum // 区间和
    #define lz(x) tree[x].lz
    #define rev(x) tree[x].rev
    #define csum0(x) tree[x].csum0 // 最大连续0
    #define csum1(x) tree[x].csum1 // 最大连续1
} tree[N * 4];

void pushup(int p) {
    sum(p) = sum(lp) + sum(rp);

    lmax0(p) = sum(lp) == 0 ? lmax0(lp) + lmax0(rp) : lmax0(lp);
    lmax1(p) = sum(lp) == r(lp) - l(lp) + 1 ? lmax1(lp) + lmax1(rp) : lmax1(lp);

    rmax0(p) = sum(rp) == 0 ? rmax0(rp) + rmax0(lp) : rmax0(rp);
    rmax1(p) = sum(rp) == r(rp) - l(rp) + 1 ? rmax1(rp) + rmax1(lp) : rmax1(rp);

    csum0(p) = max({csum0(lp), csum0(rp), rmax0(lp) + lmax0(rp)});
    csum1(p) = max({csum1(lp), csum1(rp), rmax1(lp) + lmax1(rp)});
}

void build(int p, int l, int r) {
    l(p) = l, r(p) = r, lz(p) = -1, rev(p) = 0; //  lazy set
    if(l == r) {
        sum(p) = a[l];
        csum0(p) = lmax0(p) = rmax0(p) = (a[l] == 0);
        csum1(p) = lmax1(p) = rmax1(p) = (a[l] == 1);
        return ;
    }
    int mid = l + r >> 1;
    build(lp, l, mid);
    build(rp, mid + 1, r);
    pushup(p);
}

void pushdown(int p) {
    if(lz(p) != -1) { // 有 区 间 覆 盖
        rev(p) = 0;
        int val = lz(p);

        sum(lp) = (r(lp) - l(lp) + 1) * val;
        sum(rp) = (r(rp) - l(rp) + 1) * val;

        lz(lp) = lz(rp) = val;
        rev(lp) = rev(rp) = 0;

        if(val == 0) {
            csum0(lp) = lmax0(lp) = rmax0(lp) = r(lp) - l(lp) + 1;
            csum0(rp) = lmax0(rp) = rmax0(rp) = r(rp) - l(rp) + 1;
        }
        else {
            csum0(lp) = lmax0(lp) = rmax0(lp) = 0;
            csum0(rp) = lmax0(rp) = rmax0(rp) = 0;
        }

        if(val == 1) {
            csum1(lp) = lmax1(lp) = rmax1(lp) = r(lp) - l(lp) + 1;
            csum1(rp) = lmax1(rp) = rmax1(rp) = r(rp) - l(rp) + 1;
        }
        else {
            csum1(lp) = lmax1(lp) = rmax1(lp) = 0;
            csum1(rp) = lmax1(rp) = rmax1(rp) = 0;
        }
        lz(p) = -1;
    }
    if(rev(p)) {
        sum(lp) = (r(lp) - l(lp) + 1) - sum(lp);
        sum(rp) = (r(rp) - l(rp) + 1) - sum(rp);

        if(lz(lp) != -1) lz(lp) ^= 1;
        else rev(lp) ^= 1;
        if(lz(rp) != -1) lz(rp) ^= 1;
        else rev(rp) ^= 1;

        swap(lmax0(lp), lmax1(lp));
        swap(rmax0(lp), rmax1(lp));
        swap(csum0(lp), csum1(lp));
        swap(lmax0(rp), lmax1(rp));
        swap(rmax0(rp), rmax1(rp));
        swap(csum0(rp), csum1(rp));
        rev(p) = 0;
    }
}
void change(int p, int l, int r, int tag) {
    pushdown(p);
    if(l == l(p) && r == r(p)) {
        if(tag == 0) {
            csum1(p) = sum(p) = lmax1(p) = rmax1(p) = 0;
            csum0(p) = lmax0(p) = rmax0(p) = r(p) - l(p) + 1;
            lz(p) = 0;
        }
        else if(tag == 1) {
            csum0(p) = lmax1(p) = rmax1(p) = 0;
            csum1(p) = sum(p) = lmax1(p) = rmax1(p) = r(p) - l(p) + 1;
            lz(p) = 1;
        }
        else if(tag == 2) {
            sum(p) = (r(p) - l(p) + 1) - sum(p);
            swap(lmax0(p), lmax1(p));
            swap(rmax0(p), rmax1(p));
            swap(csum0(p), csum1(p));
            rev(p) ^= 1;
        }
        return ;
    }
    int mid = l(p) + r(p) >> 1;
    if(l > mid) change(rp, l, r, tag);
    else if(r <= mid)  change(lp, l, r, tag);
    else change(lp, l, mid, tag), change(rp, mid + 1, r, tag);
    pushup(p);
}

int query(int p, int l, int r) {
    pushdown(p);
    if(l == l(p) && r == r(p))
        return sum(p);
    int mid = l(p) + r(p) >> 1;
    if(l > mid) return query(rp, l, r);
    else if(r <= mid) return query(lp, l, r);
    else return query(lp, l, mid) + query(rp, mid + 1, r);
}

Segment_tree querymax(int p, int l, int r) {
    pushdown(p);
    if(l == l(p) && r == r(p)) {
        return tree[p];
    }
    int mid = l(p) + r(p) >> 1;
    if(l > mid) return querymax(rp, l, r);
    else if(r <= mid) return querymax(lp, l, r);
    else {
        Segment_tree ret, L = querymax(lp, l, mid), R = querymax(rp, mid + 1, r);
        ret.sum = L.sum + R.sum;
        ret.l = L.l, ret.r = R.r;
        ret.csum0 = max({L.csum0, R.csum0, L.rmax0 + R.lmax0});
        ret.csum1 = max({L.csum1, R.csum1, L.rmax1 + R.lmax1});
        // cout << p << '\n';
        // cout << L.csum1 << " " << R.csum1 << " " << L.rmax1 + R.lmax1 << " \n";

        ret.rmax0 = (R.sum == 0) ? R.rmax0 + L.rmax0 : R.rmax0;
        ret.rmax1 = (R.sum == R.r - R.l + 1) ? R.rmax1 + L.rmax1 : R.rmax1;

        ret.lmax0 = (L.sum == 0) ? L.lmax0 + R.lmax0 : L.lmax0;
        ret.lmax1 = (L.sum == L.r - L.l + 1) ? L.lmax1 + R.lmax1 : L.lmax1;
        return ret;
    }
}


void solve() {
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    build(1, 1, n);
    while(m --) {
        int op, l, r;
        cin >> op >> l >> r;
        l ++, r ++;
        if(op < 3) change(1, l, r, op);
        else if(op == 3) cout << query(1, l, r) << '\n';
        else {
            // auto t = querymax(1, l, r);
            // cout << t.l << " " << t.r << " \n";
            // cout << t.csum0 << " " << t.csum1 << " |0 - 1\n";
            // cout << t.sum << " sum\n";
            cout << querymax(1, l, r).csum1 << '\n';
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}

//  unaccept