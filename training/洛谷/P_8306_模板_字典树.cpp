// 大数组memset 会很慢, 不如找找边界循环置零
#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N  = 3000010;

int son[N][63], cnt[N], idx;
map<char, int> mp;
void init() {
    for(int i = 0;i <= idx; i ++)
        for(int j = 0; j <= 122; j ++)
            son[i][j] = 0;
    for(int i = 0; i <= idx; i ++) cnt[i] = 0;
    idx = 0;
}

void insert(char *s) {
    int p = 0;
    for(int i = 0; s[i]; i ++) {
        int u = mp[s[i]];
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
        cnt[p] ++;
    }
}

int find(char *s) {
    int p = 0;
    for(int i = 0; s[i]; i ++) {
        int u = mp[s[i]];
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

char s[N];
void solve() {
    init();
    int n, m;
    scanf("%d %d", &n, &m);
    while(n --) {
        scanf("%s", s);
        insert(s);
    }
    while(m --) {
        scanf("%s", s);
        cout << find(s) << '\n';
    }
}

int main()
{
    for(int i = 0;i <= 25; i ++) mp[i + 'A'] = ++ idx;
    for(int i = 0;i <= 25; i ++) mp[i + 'a'] = ++ idx;
    for(int i = 0;i <= 9; i ++) mp[i + '0'] = ++ idx;

    int T; cin >> T;
    while(T --) solve();
    return 0;
}
