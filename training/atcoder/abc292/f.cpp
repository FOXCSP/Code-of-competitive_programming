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

ldb EPS = 1e-15;
ldb pi = 2.0 * acos(0);

void solve(int CaseT) {
    db l, r;
    cin >> l >> r;
    if (l > r) swap(l, r);
    db L = 0, R = pi / 6;
    while (R - L > EPS) {
        db mid = (L + R) / 2;
        if ((cos(pi/6-mid)*(l/cos(mid))) <= r)
            L = mid;
        else
            R = mid;
    }
    // cout << L << '\n';
    cout << (l / cos(L)) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    setdb;
    // cin >> _;
    for (int i = 1; i <= _; i++)
    {
        solve(i);
    }
    return 0;
}