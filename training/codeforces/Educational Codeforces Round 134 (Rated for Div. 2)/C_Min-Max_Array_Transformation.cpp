#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}


const int N = 2e5+10;
int n;
int a[N], b[N];
pii ans[N];
void solve() {
    cin >> n;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    for(int i = 1;i <= n;i ++) cin >> b[i];
    int idx = 1;
    for(int i = 1;i <= n;i ++) {
        int l = 1, r = n;
        while(l < r) {
            int mid = l + r >> 1;
            if(b[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }
        ans[i].first = b[l] - a[i];
        if(idx <= i) 
        {   
            idx = i;
            while(idx < n && b[idx] >= a[idx + 1]) 
                idx ++;
        }
        if(i <= idx) ans[i].second = b[idx] - a[i];
        else ans[i].second = b[i] - a[i];
    }
    for(int i = 1; i <= n;i ++) {
        cout << ans[i].first << " ";
    }
    cout << '\n';
    for(int i = 1; i <= n;i ++) {
        cout << ans[i].second << " ";
    }
    cout << '\n';    
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
