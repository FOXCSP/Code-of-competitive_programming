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

const int N = 10100;
int p[N], n, m;
ll sz[N], num[N], are[N];
vector<int> vx;

int find(int x) {
    return x != p[x] ? p[x] = find(p[x]) : x;
}

void modify(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (py < px) swap(py, px);
    if (px != py) {
        sz[px] += sz[py];
        num[px] += num[py];
        are[px] += are[py];
        p[py] = px; 
    }
}

struct name {
    int s;
    ll sz;
    double x, y;
    bool operator < (const name &R) const {
        if (y > R.y) return true;
        else if (y == R.y) {
            if (s < R.s) return true;
        }
        return false;
    }
};

void solve() {
    cin >> n;
    for (int i = 1; i <= 10000; i++) sz[i] = 1, p[i] = i;
    for (int i = 1; i <= n; i++) {
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        vx.pb(a);
        if (b != -1) modify(a, b);
        if (c != -1) modify(a, c);
        for (int j = 1; j <= k; j++) {
            int x;
            cin >> x;
            vx.pb(x);
            modify(a, x);
        }
        int x, y;
        cin >> x >> y;
        num[find(a)] += x;
        are[find(a)] += y;
    }
    // cout << "111\n";
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vector<name> ans;
    map<int, int> mp;


    for (auto x : vx) {
        int px = find(x);
        if (mp[px]) continue;
        mp[px]++;
        // cout << px << " " << sz[px] << " " << num[px] << " " << are[px] << '\n';
        ans.pb((name){px,  sz[px], 1.0 * num[px] / sz[px], 1.0 * are[px] / sz[px]});
    }
    sort(ans.begin(), ans.end());
    cout << SZ(ans) << '\n';
    for (auto x : ans) {
        // cout << x.s << " " << x.sz << " " << x.x << " " << x.y << '\n';
        printf("%04d %d %.3f %.3f\n", x.s, x.sz, x.x, x.y);
    }
}
int main()
{
    // ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
