#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 1000100;
int n, m;
int a[N];

bool check(int x) {
    int s = 0;
    for(int i = 1;i <= n;i ++) {
        if(a[i] <= x) continue;
        s += a[i] - x;
        if(s >= m) return true;
    }
    return false;
}

void solve() {
    cin >> n >> m;
    int len = 0;
    for(int i = 1;i <= n;i ++) {cin >> a[i]; len = max(len, a[i]); }
    int l = 0, r = len;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
