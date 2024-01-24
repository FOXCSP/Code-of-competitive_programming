#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 5000005, M = 21000005;
int n, son[M][2], idx, cnt[N];

void insert(int x,int i) {
    int p = 0;
    for(int i = 21; i >= 0; i --) {
        int u = (x >> i) & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] = i;
}

int f = 0;
int query(int x) {
    int res = 0;
    int p = 0;
    for(int i = 21; i >= 0; i --) {
        int u = (x >> i) & 1;
        if(son[p][u ^ 1]) {
            p = son[p][u ^ 1];
            res += 1 << i;
        }
        else {
            p = son[p][u];
        }
    }
    f = cnt[p];
    return res;
}


void solve() {
    cin >> n;
    insert(0, 0);
    int l = 0, r = 0, ans = -1, sum = 0;
    for( int i = 1;i <= n;i ++) {
        int x; cin >> x;
        sum ^= x;
        int t = query(sum);
        insert(sum, i);
        if(ans < t) {
            r = i;
            l = f;
            ans = t;
        }
    }
    cout << ans << " " << l + 1 << " " << r << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
