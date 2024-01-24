#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 55, mod = 1e9 + 7;
int ne[N], n, m;
void init(char *t) {
    int len = strlen(t + 1);
    ne[1] = 0;
    for(int i = 2, j = 0; i <= len; i ++) {
        while(j && t[i] != t[j + 1]) j = ne[j];
        if(t[i] == t[j + 1]) j ++;
        ne[i] = j;
    }
}

int f[N][N];
char s[N];
void solve() {
    cin >> n >> s + 1;
    init(s);
    m = strlen(s + 1);
    f[0][0] = 1;
    for(int i = 1; i <= n;i ++) {
        for(int j = 0; j < m ;j ++) {
            for(char k = 'a'; k <= 'z'; k ++) {
                int u = j;
                while(u && k != s[u + 1]) u = ne[u];
                if(k == s[u + 1]) u ++;
                if(u < m) {
                    f[i][u] = (f[i][u] + f[i - 1][j]) % mod;
                }
            }
        }
    }
    int res = 0;
    for(int i = 0; i < m;i ++) res = (res + f[n][i]) % mod;
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
