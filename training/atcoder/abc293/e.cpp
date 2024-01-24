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
ll A, X, M;

ll qmi(ll a, ll b) {
    a%=M;
    ll res=1;
    while(b) {
        if(b&1) res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return res%M;
}

ll query(ll p, ll c) {
    if (c == 0) return 1;
    if (c&1) return ((1+qmi(p, (c+1)/2))%M * query(p, (c-1)/2)+M)%M;
    else return (((1+qmi(p, c/2))%M * query(p, c/2-1)+M)%M + qmi(p, c))%M;
}
void solve() {
    cin >> A >> X >> M;
    A%=M;
    cout << query(A, X-1)%M << '\n';
}

signed main()
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