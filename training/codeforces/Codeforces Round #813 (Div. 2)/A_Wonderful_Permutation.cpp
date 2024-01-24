#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

const int  N = 110;
int a[N], st[N];
void solve() {
    memset(st, 0, sizeof st);
    int n, k; cin >> n >> k;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        if(i <= k) st[a[i]] = 1;
    }
    int cnt = 0;
    for(int i = 1;i <= k;i ++) {
        if(!st[i]) cnt ++;
    }
    cout << cnt << endl;
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
