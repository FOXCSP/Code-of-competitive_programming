#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const ll maxn = 1e6 + 19, mod = 19930726;
int len[maxn];
int cnt[maxn];

void manacher(char *s) {
    int n = strlen(s + 1);
    len[1] = 1; int k = 1;
    s[0] = '@', s[n+1] = '#', s[n + 2] = '\0';
    for(int i = 1;i <= n;i ++) {
        int p = k + len[k] - 1;
        if(i <= p) {
            len[i] = min(len[2*k - i], p - i + 1);
        }
        else len[i] = 1;
        while(s[i + len[i]] == s[i - len[i]]) len[i] ++;
        if(i + len[i] > k + len[k]) k = i;
        cnt[2 * len[i] - 1] ++;
    }
}

ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res % mod;
}


int n, m;
char s[maxn];
vector<int> res;
void solve() {
    cin >> n >> m >> s + 1;
    manacher(s);
    ll ans = 1;
    ll sum = 0;
    for(int i = n; i ; i --) {
        if(i % 2 == 0) continue;
        sum += cnt[i];
        if(m >= sum) {
            ans = (ans * qmi(i, sum)) % mod;
            m -= sum;
        }
        else {
            ans = (ans * qmi(i, m)) % mod;
            m = 0;
            break;
        }
    }
    if(m) cout << "-1\n";
    else cout << ans << '\n';
}

signed main()
{
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
