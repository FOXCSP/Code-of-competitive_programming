#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

int n;
const int N = 110;
char ch[N][N];
int st[N][N];
void solve() {
    cin >> n;
    int ans = 0;
    memset(st, 0, sizeof st);
    for (int i = 1; i <= n; i++) cin >> ch[i] + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (st[i][j]) continue;
            int a = ch[i][j];
            int b = ch[n - j + 1][i];
            int c = ch[n + 1 - i][n + 1 - j];
            int d = ch[j][n - i + 1];

            st[i][j] = 1;
            st[n - j + 1][i] = 1;
            st[n + 1 - i][n + 1 - j] = 1;
            st[j][n - i + 1] = 1;


            int x = 0, y = 0;
            if (a == '0') x++;
            else y++;
            if (b == '0') x++;
            else y++;
            if (c == '0') x++;
            else y++;
            if (d == '0') x++;
            else y++;
            ans += min(x, y);
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
