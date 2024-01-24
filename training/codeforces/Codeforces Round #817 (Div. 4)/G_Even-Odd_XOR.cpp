#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 2e5+10;
int n;
int ans[N], f =  123456789;

void solve() {
    cin >> n;
    bool fl = false;
    if(n % 2 == 0) {
        ans[n] = 0;
        fl = 1;
        n --;
    }
    int a = 0, b = 0;
    for(int i = 1;i <= n - 2;i ++) {
        ans[i] = (i + 1);
        if(i&1) a ^= ans[i];
        else b ^= ans[i];
    }
    // tt
    ans[n] = f ^ b;
    ans[n - 1] = f ^ a;
    if(fl) n ++;
    for(int i = 1;i <= n;i ++) cout << ans[i] << " \n"[i == n];
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while( T --) solve();
    // int a = 1 ^ 3 ^ f;
    // int b = 2 ^ 4 ^ f;
    // cout << (1 ^ 3 ^ a) << " " << (2 ^ 4 ^ b) << endl;
    return 0;
}
