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
void solve(int CaseT) {
    int n;
    cin >> n;
    vec<int> a(n+1), st(n+1, 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (st[i] == 1) st[a[i]]--;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res += (st[i]==1);
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        if (st[i]==1) cout << i << " ";
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