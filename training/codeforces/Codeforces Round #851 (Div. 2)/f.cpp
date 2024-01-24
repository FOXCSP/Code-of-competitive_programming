#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 200010;
template<class T> 
struct BIT{
    int MAX;
    vector<T> tree;
    BIT(T siz) {
        MAX = siz;
        tree.resize(MAX+100, -1e9);
    }
    void modify(int x, T y) {
        for (; x <= MAX; x += (x & -x)) tree[x] = max(tree[x], y);
    }
    T query(int x) {
        T s = -1e9;
        for (; x; x -= (x & -x)) s = max(s, tree[x]);
        return s;
    }
};
int n;
void solve() {
    cin >> n;
    vector<ll> a(n + 1, 0), vx;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        vx.pb(a[i]);
    }
    vx.pb(0);
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    static BIT<ll> mxq(SZ(vx) + 1);
    vector<ll> dp(n + 1, 0);
    int p0 = lower_bound(vx.begin(), vx.end(), 0) - vx.begin() + 1;
    mxq.modify(p0 , dp[0] - 0);
    for (int i = 1; i <= n; i++) {
        int p = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin() + 1;
        // cout << p << " " << mxq.query(p) << '\n';
        dp[i] = max(dp[i], i + mxq.query(p));
        dp[i] = max(dp[i - 1], dp[i]);
        mxq.modify(p, dp[i] - i);
    }
    cout << dp[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
