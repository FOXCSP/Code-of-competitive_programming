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
int n, k, K;
void solve(int CaseT) {
    cin >> n >> k;
    vec<ll> a(n, 0);
    // priority_queue<ll, vec<ll>, greater<ll>> heap;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<ll> s{0};
    for (int i = 0; i < k; i++) {
        ll t = *s.begin();
        s.erase(*s.begin());
        for (int j = 0; j < n; j++) {
            s.insert(t + a[j]);
        }
    }
    cout << *s.begin() << '\n';
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