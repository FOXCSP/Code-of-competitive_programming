#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = (1ll << 20);
int n;
int a[N];

bool check(int mid, int x) {
    if(a[mid] <= x) return true;
    return false;
}

int find(int x, int len) {
    int l = 1, r = len, mid, cnt = 0, w;
    while (l < r)
    {
        cnt++;
        w = rand() % 2;
        mid = (l + r + w) / 2;
        if (a[mid] - w < x)
            l = mid + !w;
        else
            r = mid - w;
    }
    return cnt;
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n;i ++) cin >> a[i];
    int m; cin >> m;
    int cnt = 0;
    while(m --) {
        int x; cin >> x;
        int ans = 1e9;
        for(int i = 1;i <= 1000;i ++) {
            ans = min(ans, find(x, n));
        }
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();    
    return 0;
}
