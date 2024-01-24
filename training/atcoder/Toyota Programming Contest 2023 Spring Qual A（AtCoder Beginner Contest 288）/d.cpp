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
ll n, k, q;
void solve() {
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    vector<vector<int>> s(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i][i % k] += a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            s[i][j] += s[i - 1][j]; 
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        vector<int> b(k);
        for (int j = 0; j < k; j++) {
            b[j] = s[r][j] - s[l - 1][j];
        }
        // for (int j = 0; j < k; j++) cout << b[j] << " \n"[j == k - 1];
        if (b == vector(k, b[0])) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
