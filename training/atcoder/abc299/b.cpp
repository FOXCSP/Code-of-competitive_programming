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
P(int) c[200010];
void solve(int CaseT) {
    int n, t;
    cin >> n >> t;
    vec<P(int)> vx, vb;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].fi;
    }
    for (int i = 1; i <= n; i++){
        cin >> c[i].se;
        if (c[i].fi == t)
            vx.pb({c[i].se, i});
        else if (c[i].fi == c[1].fi)
            vb.pb({c[i].se, i});
    }
    if (SZ(vx)) {
        sort(all(vx));
        cout << vx.back().se << '\n';
    } else {
        sort(all(vb));
        cout << vb.back().se << '\n';
    }
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