#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e7;
int son[N][26], cnt[N], idx;
char str[10];

void insert(char str[]) {
    int p = 0;
    for(int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++;
}

int query(char str[]) {
    int p = 0;
    for(int i = 0; str[i]; i ++) {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

void solve() {
    int n;
    cin >> n;
    while(n --) {
        int op;
        cin >> op >> str;
        if(op == 0) insert(str);
        else {
            if(query(str)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
