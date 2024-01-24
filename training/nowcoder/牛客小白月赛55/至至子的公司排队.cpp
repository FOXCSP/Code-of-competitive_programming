#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e5+10, mod = 1e9+7;
vector<int> g[N];
int sz[N], sz_inv[N];
ll fact[N], infact[N];

ll qmi(int a, int b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

ll c(int a, int b) {
    return (ll)fact[a] * infact[b] % mod * infact[a - b] % mod;
}

int dfs(int u) {
    int cnt = 1;
    for(auto v:g[u]) {
        cnt += dfs(v);
    }
    return sz[u] = cnt;
}

void solve() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ )
    {
        fact[i] = (ll)fact[i - 1] * i % mod;
        infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2) % mod;
    }
    int n, m, len = 0;
    ll ans = 1;
    cin >> m;
    while(m --) {
        cin >> n;
        for(int i = 2;i <= n;i ++) {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
        dfs(1);
        for(int i = 1;i <= n;i ++) {
            sz_inv[i] = qmi(sz[i], mod - 2);
        }
        // for(int i = 1;i <= n;i ++) {
        //     cout << sz_inv[i] << " ";
        // }
        // cout << endl;
        ll res = 1;
        for(int i = 1;i <= n;i ++) {
            res = 1ll * res * i % mod * sz_inv[i] % mod;
        }
        if(len == 0) ans = res;
        else ans = 1ll * ans * res % mod * c(len + n, n) % mod;
        len += n;
        // cout << ans << " " << res << endl;
        if(ans == 0) cout << c(n, len + n) << endl;
        for(int i = 1;i <= n;i ++) g[i].clear();
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}