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

const int N = 100010;
int a[N];
int b[4] = {0, 2, 1, 3};
int f[N][5];
void solve() {
    int n;
    cin >> n;
    bool f = false, g = false;
    int c = 0;
    for(int i = 1;i <= n; i++) {
        cin >> a[i];
        if(a[i] == 1) c ++;
    }
    int c1 = 0, c2 = 0;
    int id1 = 0, id2 = 0;
    for(int i = 1;i <= n; i ++) {
        if(f && a[i] == 1) c1 ++;
        if(g && a[n - i + 1] == 1) c2 ++;

        if(!f && a[i] == 2) f = true, id1 = i;
        if(!g && a[n - i + 1] == 3) g = true, id2 = n - i + 1;
    }
    int c3 = 0;
    for(int i = id1 + 1; i < id2; i ++) if(a[i] == 1) c3 ++;
    // cout << c << " " << c1 << " " << c2 << " " << c3 << " \n";
    int ans = max({c1 + 1, c2 + 1, c});
    if(f && g && c3) ans = max(ans, c3 + 2);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
