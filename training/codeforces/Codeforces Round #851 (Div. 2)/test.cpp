#include <iostream>
#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 200010;
int tree[N];
int lowbit(int x) { return (x) & (-x); }
void Upd(int idx, int x) {
    for (int i = idx; i < N; i+=lowbit(i))
        tree[i] = max(tree[i], x);
}
 
int Max(int idx) {
    int res = -1e9;
    for (int i = idx; i >= 1; i -= lowbit(i))
        res = max(res, tree[i]);
    return res;
}
// ====== 树状数组 ==============
 
int n, a[N];
ll pre[N], C[N];
int s[N], dp[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + a[i];
    memcpy(C, pre, sizeof(pre));
    sort(C, C + 1 + n);
    int l = unique(C, C + 1 + n) - C;
    for (int i = 0; i <= n; ++i)
        s[i] = lower_bound(C, C + l, pre[i]) - C + 1;
    for (int i = 0; i < N; i++)tree[i] = -1e9;
    dp[0] = 0;
    cout << s[0] << '\n';
    Upd(s[0], dp[0] - 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = Max(s[i]) + i;
        cout << Max(s[i]) << " " << s[i] << '\n';
        dp[i] = max(dp[i], dp[i - 1]);
        Upd(s[i], dp[i] - i );
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " \n"[i == n];
    }
    cout << dp[n] << endl;
    return 0;
}