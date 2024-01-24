#include <bits/stdc++.h>
// #define int long long
#define P(T) pair<T, T>
#define pb push_back
#define lp (p<<1)
#define rp (p<<1|1)
#define SZ(T) (int)(T.size())
using namespace std;
using ll = long long;

ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

int n;

void solve() {
    cin >> n;
    vector<int> ans(n + 1), a(n + 1, 0);
    vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - 1; j++) {
            cin >> t[i][j];
            if (j == n - 1) mp[t[i][j]]++;
        }
    }
    int x = 0, y = 0;
    for (auto c : mp) {
        if (y < c.second) {
            y = c.second;
            x = c.first;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (t[i][n - 1] != x) {
            for (int j = 1; j < n; j++) cout << t[i][j] << " ";
            cout << x << '\n';
            return ;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
