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

void solve(int CaseT) {
    string s;
    cin >> s;
    ll ans = 0; 
    for (int i = 0; i < SZ(s); i++) {
        if (s[i] > '0' && s[i] <= '9') ans++;
        else {
            if (s[i] == '0' && i + 1 < SZ(s) && s[i + 1] == '0') ans++,i++;
            else ans++;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    // cin >> _;
    for (int i = 1; i <= _; i++)
    {
        solve(i);
    }
    return 0;
}