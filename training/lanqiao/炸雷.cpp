#include <bits/stdc++.h>
#define int long long
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

const int N = 50010;
bool st[N];
int n, m;
array<int, 3> a[N], b[N];
int ans;
void dfs(array<int, 3> p) {
    int l,r;
    l=1,r=n;
    while (l<r) {
        int mid=(l+r)/2;
        if (a[mid][0] < p[0]-p[2]) l=mid+1;
        else r=mid;
    }
    int pl = l;
    l=1,r=n;
    while (l<r) {
        int mid=(l+r+1)/2;
        if (a[mid][1] <= p[0]+p[2]) l=mid;
        else r=mid-1;
    }
    int pr=l;
    auto dist = [&](array<int, 3> x, array<int, 3>y) {
        return x[2] >= sqrtl((x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]));
    };
    for (int i=pl; i<=pr;i++) {
        if(!st[i] && dist(p, a[i])) {
            st[i]=1;
            ans++;
            dfs(a[i]);
        }
    }
}
void solve() {
    cin >> n >> m;
    for (int i=1; i<=n;i++) cin >> a[i][0]>>a[i][1]>>a[i][2];
    for (int i=1; i<=m;i++) cin >> b[i][0]>>b[i][1]>>b[i][2];
    sort(a+1,a+n+1);
    for (int i=1; i<=m;i++) {
        dfs(b[i]);
        if (ans>=n) break;
    }
    cout<<ans<<'\n';
}

signed main() {
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