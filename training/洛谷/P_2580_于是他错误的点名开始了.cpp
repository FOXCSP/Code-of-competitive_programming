#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int  N = 1e7+10;
int son[N][30], cnt[N], idx;

void insert(char *str) {
    int p = 0;
    for(int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p] ++;
}
int query(char *str) {
    int p = 0;
    for(int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    if(cnt[p]) cnt[p] ++;
    return cnt[p];
}

void solve() {
    int n;
    cin >> n;
    while(n --) {
        char str[55];
        cin >> str;
        insert(str);
    }

    int m; cin >> m;
    while(m --) {
        char str[55];
        cin >> str;
        int t = query(str);
        if(t == 2) cout << "OK\n";
        else if(t > 2) cout << "REPEAT\n";
        else cout << "WRONG\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
