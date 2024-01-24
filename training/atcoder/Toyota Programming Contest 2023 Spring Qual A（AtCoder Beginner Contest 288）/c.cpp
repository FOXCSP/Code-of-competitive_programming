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

const int N = 200010;
int n, m;
int p[N];
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
void solve() {
    cin >> n >> m;
    int cnt = n, x = 0;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        int pu = find(u);
        int pv = find(v);
        if (pu != pv) {
            cnt--;
            p[pu] = pv;
            x++;
        }
    }
    cout << m - x << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
