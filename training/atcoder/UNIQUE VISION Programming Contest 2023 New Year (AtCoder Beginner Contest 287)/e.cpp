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

const int N = 500010;
int tr[N * 2][26], sz[N];
int idx = 0;
int find(string s) {
    int p = 0, res = 0;
    for (auto x : s) {
        int u = x - 'a';
        if (!tr[p][u]) {
            return res;
        }
        p = tr[p][u];
        if (sz[p] >= 2) res++;
        else return res;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        int p = 0;
        for (auto c : s[i]) {
            int u = c - 'a';
            if (!tr[p][u]) tr[p][u] = ++idx;
            p = tr[p][u];
            sz[p]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (find(s[i])) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
