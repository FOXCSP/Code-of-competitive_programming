#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using ull = unsigned long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const ull mod = 212370440130137957ll, tag = 1331, base = 131;
ull Hash(char *str) {
    int len = strlen(str);
    ull ans = 0;
    for(int i = 0; i < len; i ++)
        ans = (ans * base + (ull)str[i]) % mod + tag;
    return ans;
}
const int N = 1e5+10;
char s[N];
ull a[N];
void solve() {
    int n; cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> s;
        a[i] = Hash(s);
    }
    sort(a + 1, a + n + 1);
    int cnt = 1;
    for(int i = 1; i < n;i ++) {
        if(a[i] != a[i + 1]) cnt ++;
    }
    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
