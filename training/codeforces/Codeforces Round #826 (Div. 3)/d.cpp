#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
int a[N];
int get(int l, int r) {
    if (l == r) return 0;
    int mid = l + r >> 1;
    int mal = *max_element(a + l, a + mid);
    int mar = *max_element(a + mid + 1, a + r);
    int ans = 0;
    if (mal > mar) {
        ans ++;
        for (int i = l, j = mid + 1; i <= mid; i ++, j ++)
            swap(a[i], a[j]);
    }
    return get(l, mid) + get(mid + 1, r) + ans;
}


void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    int t = get(1, n);
    if (is_sorted(a + 1, a + n + 1)) cout << t << '\n';
    else cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int _; cin >> _; while(_ --) solve();
    return 0;
}