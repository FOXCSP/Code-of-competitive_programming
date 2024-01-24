// https://atcoder.jp/contests/abc293/submissions/40356373
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
const int N = 400010;
int n, m;
int p[N], op[N], sz[N];
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py) {
        p[py] = px;
        sz[px] += sz[py];
        op[px] += op[py] + 1;
    }
    else op[px]++;

}

void solve(int CaseT) {
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++) p[i] = i, sz[i] = 1;
    for (int i = 1; i <= n; i++) {
        merge(i, i + n);
    }
    for (int i = 1; i <= m; i++) {
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        merge(a + (b=='R')*n, c + (d=='R')*n);
    }
    int ans1 = 0, ans2 = 0;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x = find(i);
        if (mp.count(x)) continue;
        mp[x]++;
        // cout << sz[x] << " " << op[x] << '\n';
        if (sz[x] == op[x] + 1) {
            ans2++;
        } else if (sz[x] == op[x]) {
            ans1++;
        }
    }
    cout << ans1 << " " << ans2 << '\n';
}
int main() {
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