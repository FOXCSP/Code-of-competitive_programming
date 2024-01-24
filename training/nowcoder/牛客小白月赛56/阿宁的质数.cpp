#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 3.5e6+10;
int prime[N], cnt;
unordered_map<int, int> vis;

void Prime() {
    for(int i = 2; i <= N;i ++) {
        if(vis.count(i) == 0) prime[cnt ++] = i;
        for(int j = 0;j < cnt && prime[j] * i <= N ; j ++) {
            vis[i * prime[j]] ++;
            if(i % prime[j] == 0) break; 
        }
    }
}
int a[N];
void solve() {
    int n, m;
    cin >> n >> m;
    Prime();
    // cout << cnt  << endl;
    // for(int i =1;i <= n;i++)cout << prime[i] << " ";
    // cout <<endl;
    int t = prime[0], idx = 0;
    unordered_map<int,int> mp;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        if(vis.count(a[i]) == 0) mp[a[i]] ++;
        while(mp.count(t) == 1) t = prime[idx ++];
        a[i] = t;
    }
    while(m --) {
        int x;
        cin >> x;
        cout << a[x] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
