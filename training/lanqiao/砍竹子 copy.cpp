#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;

// -- head--

bool operator < (const P(int) L, const P(int) R) {
    return (L.fi < R.fi || L.se > R.se);
}

struct node {
    int x, y;
    bool operator < (const node& R) const {
        if (x != R.x) return x < R.x;
        return y > R.y;
    }
};

void solve(int CaseT) {
    int n;
    cin >> n;
    vec<ll> a(n), pre(n);
    vec<ll> vx;
    priority_queue<node> heap;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre[i] = a[i];
        heap.push({a[i], i});
    }


    ll ans = 0;

    // while (heap.size()) {
    //     cout << heap.top().x << " " << heap.top().y << '\n';
    //     heap.pop();
    // }


    
    while (heap.top().x > 1) {
        // cout << heap.top().x << " " << heap.top().y << '\n';
        node t = heap.top();
        int pos = t.y, cur = t.x;
        while (heap.top().x >= cur) {
            // cout << heap.top().x << " " << heap.top().y << '\n';
            int x = heap.top().x, y = heap.top().y;
            heap.pop();
            if (y && a[y] == pre[y-1]) {
                pre[y] = a[y];
                a[y] = a[y-1];
                // cout << "111 change: a[" << y << "] -> " << a[y] << " ans= " <<ans<<'\n';
                heap.push({a[y], y});
                continue;
            }
            ll res=0;
            while (x >= cur && x > 1) {
                x = (sqrtl(x/2+1));
                res++;
            }
            ans+=res;
            pre[y] = a[y];
            a[y] = x;
            // cout << "222 change: a[" << y << "] -> " << a[y] << " ans=" << ans<<'\n';
            heap.push({a[y], y});
        }
    }

    cout << ans << '\n';
}

signed main() {
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