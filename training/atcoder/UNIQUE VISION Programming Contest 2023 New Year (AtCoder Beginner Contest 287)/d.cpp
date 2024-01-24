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
    string s, t;
    cin >> s >> t;
    int ls = s.size(), lt = t.size();
    s = "#" + s;
    t = "#" + t;
    int n = ls;
    vector<int> suf(n + 2, 0), pre(n + 1, 0);
    for (int i = 1, j = 1; i <= ls && j <= lt; i++, j++) {
        if (s[i] == t[j] || s[i] == '?' || t[j] == '?')
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = pre[i - 1];
    }
    for (int i = ls, j = lt; i >= 1 && j >= 1; i--, j--) {
        if (s[i] == t[j] || s[i] == '?' || t[j] == '?')
            suf[i] = suf[i + 1] + 1;
        else
            suf[i] = suf[i + 1];
    }
    for (int x = 0; x <= lt; x++) {
        if (pre[x] + suf[ls - (lt - x) + 1] == lt) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
