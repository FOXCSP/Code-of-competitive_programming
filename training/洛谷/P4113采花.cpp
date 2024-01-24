#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

int n, m;
const int N = 200010;

int a[N];

struct seg{
    int val;
    int lz, sz;
    seg operator + (const seg& R) const {
        return {val + R.val, lz + R.lz, sz + R.sz};
    }
} tr[N * 4];

void pushup(int p) {
    tr[p] = tr[lp] + tr[lp];
}

void build(int p, int l, int r) {
    tr[p].sz = r - l + 1;
    tr[p].lz = 0;
    if (l == r) {
        tr[p] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(lp, l, mid);
        build(rp, mid + 1, r);
    }
}

void solve() {
    cin >> n >> m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    for (int i = 1; i <= _; i++) {
        solve();
    }
    return 0;
}