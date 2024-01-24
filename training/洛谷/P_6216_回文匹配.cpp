#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int Maxn = 3e6 + 10, mod = (1 << 32);
char a[Maxn], b[Maxn];
int n, m;
int ne[Maxn];

void init() {
    ne[1] = 1;
    for(int i = 1, j = 0;i <= m;i ++) {
        while(j > 0 && b[i] != )
    } 
}


void solve() {
    cin >> n >> m >> a + 1 >> b + 1;

}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
