#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define pb push_back
#define rp (p<<1|1)
#define lp (p<<1)
#define endl '\n'
#define fi first
#define se second
// #define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 110, mod = 1e6 + 7;
int n, m;
vector<int> e;
int f[N];
void solve() {
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1;i <= n; i ++) {
        int s;
        cin >> s;
        for(int j = m; j >= 0; j --)
            for(int k = 1; k <= j && k <= s; k ++)
                f[j] = (f[j] + f[j - k]) % mod;
    }
    cout << f[m] << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
