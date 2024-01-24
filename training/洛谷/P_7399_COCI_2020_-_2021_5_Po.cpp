#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 100010;
int stk[N], n, t = 0;
void solve() {
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n; i ++) {
        int x; cin >> x;
        while(t > 0 && stk[t] > x) t --;
        if(t > 0 && stk[t] == x) continue;
        if(x) {
            stk[++ t] = x;
            ans ++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
