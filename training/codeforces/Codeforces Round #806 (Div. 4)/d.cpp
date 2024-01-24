#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 100010;
map<string, int> mp;
int n;
string a[N];

void solve() {
    cin >> n;
    mp.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 1; i <= n; i ++) {
        int x = a[i].size();
        bool f = 0;
        for (int j = 1; j < x; j++) {
            string s1 = a[i].substr(0, j);
            string s2 = a[i].substr(j, x - j);
            if (mp[s1] && mp[s2]) {
                f = 1;
                break;
            }
        }
        cout << f;
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
