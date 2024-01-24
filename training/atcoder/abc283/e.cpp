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
    int h, w;
    cin >> h >> w;
    vec<vec<int>> a(h+1, vec<int> (w + 1, 0));
    vec<int> pos[h + 1];
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            cin >> a[i][j];
        for (int j = 1; j <= w; j++) {
            bool f = 0;
            if (j > 1) f += (a[i][j] == a[i][j - 1]);
            if (j < w) f += (a[i][j] == a[i][j + 1]);
            if (!f) pos[i].pb(j);
        }
    }
    int ans = 0;
    vec<int> pr(h + 1, 0);
    ans = 0;
    for (int i = 1; i <= h; i++) {
        cout << i << " : ";
        for (auto x : pos[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }

    for (int i = 2; i <= h; i++) {
        for (int j = 0; j < SZ(pos[i]); j++) {
            int p = a[i][pos[i][j]];
            int q = a[i - 1][pos[i][j]];

            if (pr[i - 1]) q ^= 1;
            if (pr[i]) p ^= 1;

            if (p != q) {
                if (pr[i]) {
                    cout << " gg: " << i << '\n';
                    cout << "-1\n";
                    return ;
                }
                pr[i] = 1;
                cout << "fan : " << i << '\n';
                ans++;
            }
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