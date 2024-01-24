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

int n;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26, 0), pos(26, 0);
    int len = 0;
    int n = SZ(s);
    s = "#" + s;
    for (int i = 1; i <= n; i++) {
        int u = s[i] - 'a';
        if (pos[u]) {
            len += 2;
            for (int j = 0; j < 26; j++) {
                pos[j]=0;
            }
        } else pos[u]++;
    }
    cout << n - len << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
