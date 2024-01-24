#include <bits/stdc++.h>
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

const int N = 3010;
const ll mod = 1000000007;
ll pw[N], px[N];
int n;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> px[i];
    }
    px[n + 1] = 2e9;
    pw[0] = 1; 
    for (int i = 1; i <= n; i++) pw[i] = (pw[i - 1] * 2) % mod;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = i;
        for (int j = i + 1; j <= n; j++) {
            // 如果将直接枚举 l, r那么时间复杂度O(n^3)
            // 因为区间越枚举越大，所以将l, r放在外围枚举；
            // 假设枚举[i, i + 1] -> [l, r] = [i, i + 4], 但枚举[i, i + 2], [l, r]会重新被枚举, 实际上[i + 3, i + 4]已经不符合，因为他无法满足d[i+1]-d[i]，就更不会满足d[i+2]-d[i]
            // i -> end <- j
            // 选择了i, j两点，i，j中间不选；
            // i 不能 <-： 找到第一个px[i] - p[l] > p[j] - p[i]
            // j 不能 ->： 找到第一个px[r] - p[j] > p[j] - p[i]
            // tie -> 左移，所以要刨去l的等于号
            // 
            while (l > 0 && px[i] - px[l] <= px[j] - px[i]) l--;
            while (r <= n && px[r] - px[j] < px[j] - px[i]) r++;
            ans = (ans + pw[l] * pw[n - r + 1] % mod) % mod;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
