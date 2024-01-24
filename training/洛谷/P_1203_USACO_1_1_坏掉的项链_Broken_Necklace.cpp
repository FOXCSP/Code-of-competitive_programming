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

const int N = 800;
char s[N];
int n;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i];
        s[i + n] = s[i];
    }
    int l = 0, r = 0, w = 0, ans = 0;
    char now;

    for(int i = 1;i <= n<<1;i ++) {
        if(s[i] == 'w') w ++, r ++;
        else if(s[i] == now) w = 0, r ++;
        else {
            ans = max(ans, l + r);
            l = r - w;
            r = w + 1;
            w = 0;
            now = s[i];
        }
    }
    ans = max(ans, l + r);
    cout << min(n, ans) << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}