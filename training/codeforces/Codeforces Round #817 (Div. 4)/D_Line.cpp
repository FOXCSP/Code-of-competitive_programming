#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N  = 2e5 + 10;
int n;
char s[N];
int k[N];
void solve() {
    cin >> n >> s + 1;
    int l = 1, r = n, idx = 0;
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        if(s[i] == 'L') ans += i - 1;
        else ans += n - i;
    }
    // cout << ans << endl;
    while(l < r) {
        if(s[l] == 'L') {
            ans += (n - l) - (l - 1);
            k[++ idx] = ans;
        }
        if(s[r] == 'R') {
            ans += (r - 1) - (n - r);
            k[++ idx] = ans;
        }
        l ++, r --;
    }
    for(int i = 1;i <= n;i ++) {
        if(i < idx) cout << k[i] << " ";
        else cout << ans << " ";
    }
    cout << "\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
