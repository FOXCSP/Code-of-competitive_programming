#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 500010;
int a[N], b[N], n, c[N];

ll query(int x) {
    ll res = 0;
    for(; x; x -= x & -x) res += c[x];
    return res;
}

void add(int x, int y) {
    for(; x <= n; x += x & -x) c[x] += y;
}

void solve() {
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
        b[i] = i;
    }
    stable_sort(b + 1, b + n + 1, [] (int i, int j) {return a[i] < a[j];});
    ll ans = 0;
    for(int i = n; i; i --) {
        ans += query(b[i] - 1);
        add(b[i], 1);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
