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

void solve(int CaseT) {
    int n;
    cin >> n;
    vec<int> a(n + 1, 0), ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    /*
    // n -> 1
    stack<P(int)> stk;
    for (int i = n; i >= 1; i--) {
        while (SZ(stk) && stk.top().fi <= a[i]) 
            stk.pop();
        if (SZ(stk) == 0) ans[i] = 0;
        else ans[i] = stk.top().se;
        stk.push({a[i], i});
    }
    */

    // 1 -> n

    stack<P(int)> stk;
    for (int i = 1; i <= n; i++) {
        while (SZ(stk) && stk.top().fi < a[i]) {
            ans[stk.top().se] = i;
            stk.pop();
        }
        stk.push({a[i], i});
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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