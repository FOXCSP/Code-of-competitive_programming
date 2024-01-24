// 大数组memset 会很慢, 不如找找边界循环置零
#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N  = 3000010;

int son[N][26], cnt[N], idx;
int ans = 0;
void insert(char *s) {
    int p = 0;
    for(int i = 0; s[i]; i ++) {
        int u = s[i] - 'A';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
        cnt[p] ++;
    }
}

char s[N];
void solve() {
    while(cin >> s) {
        insert(s);
    }
    cout << idx + 1 << '\n';
}

int main()
{
    solve();
    return 0;
}
