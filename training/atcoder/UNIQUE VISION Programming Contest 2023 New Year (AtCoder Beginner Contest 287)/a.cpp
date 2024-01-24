#include <bits/stdc++.h>
#define hashset_finetune(p) p.reserve(1024);p.max_load_factor(0.25); // hashset_finetune(demo)
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

void solve() {
    int n, a = 0, b = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s == "For") a++;
        else b++;
    }
    puts(a > b ? "Yes" : "No");
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
