#include <bits/stdc++.h>
const int N = 5e5 + 10;
using namespace std;
using LL = long long;
vector<vector<int>> g;
int n,k,sum,ans;
int siz[N];
void dfs1(int u,int fa){
    siz[u] = 1;
    for(auto e : g[u]){
        if(e == fa) continue;
        dfs1(e,u);
        siz[u] += siz[e];
    }
}
vector<int> a;
void dfs2(int u,int fa){
    if(siz[u] >= k) a.push_back(siz[u]);

    for(auto e : g[u]){
        if(e == fa) continue;
        if(a.size()){
            int l = 0, r = a.size() - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(a[mid] - siz[e] - 1 < k) r = mid;
                else l = mid + 1;
            }
            if(a[l] - siz[e] - 1 < k){
                int cnt = a.size() - l;
                // cerr << u << ' ' << 
                ans = min(ans, sum - cnt);
            }
        }
        dfs2(e,u);
    }

    if(siz[u] >= k) a.pop_back();
}

signed main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> n >> k;
    g.resize(n+1);

    for(int i = 1; i <= n - 1; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs1(1,-1);
    for(int i = 1;i <= n; ++i) {
        siz[i]--;
        sum += (siz[i] >= k);
    }

    ans = sum;
    // cerr << ans;
    dfs2(1,-1);
    cout << ans;

}
