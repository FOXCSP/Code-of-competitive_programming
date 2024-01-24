// 区间石子合并有特殊的定理

#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
#define FOR(x, l, r) for(int x = l;x <= r; x ++)
#define FRO(x, r, l) for(int x = r;x >= l; x --)
#define For(x, l, r) for(int x = l;x < r;  x ++)
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

const int N = 40010;
int n;
bool st[N];
vector<int> a;
void solve() {
    cin >> n;
    a.pb(2e9);
    FOR(i, 1, n) {
        int x;
        cin >> x;
        a.pb(x);
    }
    a.pb(2e9);
    // cout << a.size() << endl;
    int ans = 0;
    FRO(i, n, 2) {
        // 找到最小的Ak-1 < Ak + 1
        int k = 1;
        FOR(K, 1, i) if(a[K - 1] <= a[K + 1]) {
            k = K;
            break;
        }
        int sum = a[k - 1] + a[k];
        int t = k - 1;
        FRO(T, k - 1, 0) if(a[T] > sum) {
            t = T;
            break;
        }
        a.erase(a.begin() + k - 1), a.erase(a.begin() + k - 1);
        a.insert(a.begin() + t + 1, sum);
        ans += sum;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
