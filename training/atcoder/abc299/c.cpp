#include <bits/stdc++.h>
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
P(int) c[200010];
void solve(int CaseT) {
    string s;
    int n;
    cin >> n;
    cin >> s;
    int l = -1, r = -1;
    int ans = -1, cnt = 0;
    for (int i = 0; i < SZ(s); i++) {
        if (s[i] == 'o') cnt++;
        if (s[i] == '-') {
            if (cnt) ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cnt = 0;
    for (int i = SZ(s) - 1; i >= 0; i--) {
        if (s[i] == 'o') cnt++;
        if (s[i] == '-') {
            if (cnt) ans = max(ans, cnt);
            cnt = 0;
        }
    }
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