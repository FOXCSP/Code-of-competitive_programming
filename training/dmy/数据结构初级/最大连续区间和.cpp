#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--
const ll mod = 1e9 + 7;


const int N = 100010;
int n, l, r;
int s[N], a[N];

struct seg {
    int val, id;
    seg operator + (const seg& R) const {
        seg res;
        if (val > R.val)
            res.id = id;
        else 
            res.id = R.id;

        res.val = max(val, R.val);
        return res;
    }
} tr[N << 4];

void pushup(int p) {
    tr[p] = tr[lp] + tr[rp];
}

void build(int p, int l, int r) {
    if (l == r) {
        tr[p].val = s[l], tr[p].id = l;
    } else {
        int mid = (l + r) / 2;
        build(lp, l, mid);
        build(rp, mid + 1, r);
        pushup(p);
    }
}

seg query(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tr[p];
    int mid = l + r >> 1;
    seg val = {(int)-1e9, 0};
    if (L <= mid) val = val + query(lp, l, mid, L, R);
    if (R >  mid) val = val + query(rp, mid + 1, r, L ,R);
    return val;
}



void solve(int CaseT) {
    cin >> n;
    cin >> l >> r;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    build(1, 1, n);
    int ans = -(1 << 30);
    for (int i = 1; i + l - 1 <= n; i++) {
        auto x = query(1, 1, n, i + l - 1, min(n, i + r - 1));
        ans = max(ans, x.val - s[i - 1]);
    }
    cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int _;
	_ = 1;
	// cin >> _;
	for (int i = 1; i <= _; i++) {
		solve(i);
	}
	return 0;
}