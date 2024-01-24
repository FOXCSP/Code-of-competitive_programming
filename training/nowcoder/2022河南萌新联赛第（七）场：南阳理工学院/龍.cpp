#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 3e5+10;
char s[N];
void solve() {
    int n, a, b, x;
    cin >> n >> a >> b >> x;
    cin >> (s + 1);
    int l = 1, r = n, res = 0, res1 = 0;
    for(int i = 1;i < n;i ++) {
        if(s[i] == '0' && s[i+1] == '1') res ++;
        if(s[i] == '1' && s[i+1] == '0') res1 ++;
    }
    if(s[n] == '0') res ++;
    if(res1 > 0 && s[1] == '1') res1 --;
    // cout << res << " " << res1 << endl;
    int cost = res1*a + b;
    cost = min(cost, b*res);
    if(x >= cost)
        cout << "Yes\n" << x - cost << "\n";
    else cout << "No\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
