// https://codeforces.com/contest/1702/submission/192624190
#include <bits/stdc++.h>
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

const int N = 400010;
int p[N], n;
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) p[x] = y;
}

void solve() {
    cin >> n;
    
    for (int i = 1; i <= 2 * n; i++) p[i] = i;
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        merge(x, n + y);
        merge(n + x, y);
        cnt[x]++;
        cnt[y]++;
    }
    if (*max_element(cnt.begin(), cnt.end()) > 2) {
        cout << "NO\n";
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (find(i) == find(i + n)) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}