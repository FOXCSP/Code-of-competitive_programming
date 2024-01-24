#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define pb push_back
#define rp (p<<1|1)
#define lp (p<<1)
#define endl '\n'
#define fi first
#define se second
// #define int long long

using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int N = 200010;
int n, m;
int p[N];
int find(int x) {
    return x != p[x] ? p[x] = find(p[x]) : x;
}
void solve() {
    cin >> n >> m;
    vector<int> indig(n + 1, 0), outdig(n + 1, 0);
    for (int i = 1; i <= n; i++) p[i] = i;
    int res = n;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        outdig[u]++;
        outdig[v]++;
        indig[u]++;
        indig[v]++;
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            p[pv] = pu;
            res--;
        }
    }
    bool f = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (indig[i] > 2 || outdig[i] > 2)
            f = false;
        if (indig[i] == 1 && outdig[i] == 1)
            cnt++;
        if (indig[i] == 0 || outdig[i] == 0)
            f = false;
    }
    if (n != m + 1) f = false; 
    puts((res == 1 && f && cnt == 2) ? "Yes" : "No");
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
