#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const double eps = 1e-1;

double a, b, c, d;
void solve() {
    cin >> a >> b >> c >> d;
    int x = a * d - b * c;
    if(abs(x) == 1 || x == 0) cout << "YES\n";
    else cout << "NO\n"; 
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
