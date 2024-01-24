#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

const int N = 1e5+10;
int n, m;
int a[N];
int cnt[N];
void solve() {
    memset(cnt, 0, sizeof cnt);
    cin >> n >> m;
    int idx = 0;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        if(a[i] == n) idx = i;
    }
    int t = a[1], ti = 1;
    pii act[N];
    act[a[1]] = {1, 1};
    for(int i = 1;i <= n;i ++) {
        if(t > a[i]) cnt[t] ++, act[t].second = i;
        else if(t < a[i]) {
            cnt[a[i]] ++, t = a[i];
            act[a[i]].first = i - 1;
            ti = i;
        }
    }
    // cout << act[10].first << " " << act[10].second << endl;
    while(m --) {
        int x, y;
        cin >> x >> y;
        if(a[x] == n) {
            if(y < idx - 1) cout << "0" << endl;
            else {
                if(idx - 2 > 0) y -= (idx - 2);
                cout << y << endl;
            }
        }
        else {
            if(y < act[a[x]].first) cout << "0" << endl;
            else {
                // cout << cnt[5] << endl;
                cout << min(y-act[a[x]].first+1, cnt[a[x]]) << endl;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}
