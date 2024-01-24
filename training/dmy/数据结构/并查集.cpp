#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout<<fixed<<setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

const int N = 4000010;
const ll mod = 998244353;

int p[N], n, m;

int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}

ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void solve(int CaseT) {
    cin >> n >> m;
    int op, u, v;
    string ans="";
    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        cin >> op >> u >> v;
        int pu = find(u);
        int pv = find(v);
        if (op == 0) {
            if (pu != pv)
                p[pu] = pv;
        } else {
            ans.pb((pu == pv) ? '1' : '0');
        }
    }
    reverse(all(ans));
    ll res=0;
    for (int i = 0; i < SZ(ans); i++) {
        res = (res + qmi(2, i) * (ans[i] == '1')) % mod;
    }
    cout << res << '\n';
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