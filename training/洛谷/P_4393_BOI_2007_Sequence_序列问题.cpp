#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int n, m, a[N];
void solve() {
    cin >> n;
    long long ans = 0;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    for(int i = 1;i < n;i ++) ans += max(a[i], a[i + 1]);
    cout << ans << endl;
}

int main () {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}