#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

int N;
int p = 998244353;
void solve() {
    cin >> N;
    int t = ((int)1e18) / p;
    int x = (N + (t+1ll) * p) % p;
    cout << x  << endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}