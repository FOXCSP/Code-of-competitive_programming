#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define lp (p<<1)
#define rp (p<<1|1)
#define pb push_back
#define P(T) pair<T,T>
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define setdb cout<<fixed<<setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

const int N = 100010;
vec<array<ldb, 3>> edge;
vec<P(ldb)> node;
int p[N], n, m;
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
ldb dis(P(ldb) a, P(ldb) b) {
    return sqrtl((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}
void solve(int CaseT) {
    cin >> n;
    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        node.pb({x, y});
    }

    for (int i = 0; i < SZ(node); i++) {
        for (int j = 0; j < SZ(node); j++) {
            if (i != j) {
                edge.pb((array<ldb, 3>){dis(node[i], node[j]), 1.0 * i + 1, 1.0 * j + 1});
            }
        }
    }

    sort(all(edge));
    int res = n;
    ldb ans = 0;
    for (auto x : edge) {
        int px = find(x[1]);
        int py = find(x[2]);
        if (px != py) {
            res--;
            p[px] = py;
            ans += x[0];
        }
    }
    cout << fixed << setprecision(1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int _;
    _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; i++) {
        solve(i);
    }
    return 0;
}