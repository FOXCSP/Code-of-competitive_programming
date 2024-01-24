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

const int N = 200010, M = 210;

set<string> P;
string a, s;
bool dp[N];
int ans = 0;
void solve() {
    int len = 0;
    while(cin >> a) {
        if(a == ".") break;
        P.insert(a);
        len = max(len, (int)a.size());
    }
    while(cin >> a) s += a;
    int n = s.size();
    s = '0' + s;
    for(int i = 1;i <= n;i ++) {
        while(dp[i + len - 1]) i ++;
        for(int j = 1; j <= len; j ++) {
            string tmp = s.substr(i, j);
            if(P.find(tmp) != P.end()) {
                for(int t = i; t <= i + j - 1; t ++ ) dp[t] = true;
            }
        }
    }
    int ans = 1;
    while(ans <= n && dp[ans]) ans ++;
    cout << ans - 1 << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
