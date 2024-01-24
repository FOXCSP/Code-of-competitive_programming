#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 110;

int n;
int a[N];
void solve() {
    cin >> n;
    int ans=  0;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        if(a[i] & 1) {
            ans = i;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
