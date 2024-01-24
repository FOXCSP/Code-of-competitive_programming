#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 110, M = 210;
int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N];
bool st[N];
void add(int a,int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int x, y;

void spfa(int s) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[s] = 0;
    queue<int> q;
    st[s] = 1;
    q.push(s);
    while(q.size()) {
        int t = q.front(); q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1;i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if(!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

void solve() {
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1;i < n; i ++ ) {
        int a, b;
        cin >> a >> b;
        add(a, b, 1), add(b, a, 2);
    }
    cin >> x >> y;
    spfa(1);
    // for(int i = 1; i <= n;i ++) {
    //     cout << dist[i] << " \n"[i == n];
    // }
    int ans = 0;
    for(int i = 1;i <= n;i ++) ans = max(ans, dist[i]);
    cout << ans + 1 << '\n';
    ans = 0;
    vector<int> cnt;
    cnt.resize(n+1, 0);
    for(int i = 1;i <= n;i ++) cnt[dist[i]] ++, ans = max(ans, cnt[dist[i]]);
    cout << ans << '\n';
    spfa(x);
    cout << dist[y] << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
