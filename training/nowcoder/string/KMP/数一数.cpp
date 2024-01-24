#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 2e6+10, mod = 998244353;
int ne[N], f[N];
int lens, lent;
void KMP_pre(string T) {
    ne[1] = 0;
    for(int i = 2, j = 0; i <= lent;i ++) {
        while(j > 0 && T[i] != T[j+1]) j = ne[j];
        if(T[i] == T[j+1]) j ++;
        ne[i] = j;
    }
}

int KMP(string S, string T) {
    int cnt = 0;
    for(int i = 1, j = 0; i <= lens; i  ++) {
        while(j > 0 && (j == lent || S[i] != T[j + 1])) j = ne[j];
        if(S[i] == T[j + 1]) j ++;
        f[i] = j;
        if(j == lent) cnt ++, j = ne[j];
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector<string> str(n+1);
    int len = 2e6+10, idx = 0;
    for(int i = 1;i <= n;i ++) {
        cin >> str[i];
        if(len > str[i].size()) {
            len = str[i].size(); idx = i;
        }
        str[i] = " " + str[i];
    }
    ll ans = 1;
    lent = len;
    KMP_pre(str[idx]);
    for(int i = 1;i <= n; i ++) {
        lens = str[i].size() - 1;
        ans = 1ll * ans % mod * KMP(str[i], str[idx]) % mod;
    }

    for(int i = 1;i <= n;i ++) {
        if(str[i] != str[idx]) cout << "0\n";
        else cout << ans << "\n";
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
