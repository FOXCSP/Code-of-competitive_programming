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

ll a, b, c;
void solve() {
    cin >> a >> b >> c;
    if(a&1) {
        if(c&1) {
            if(b&1) cout << "0\n";
            else cout << "1\n";
        }
        else cout << "1\n";
    }
    else {
        if(c&1) {
            if(b&1) cout << "1\n";
            else cout << "0\n";
        }
        else {
            cout << "0\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}