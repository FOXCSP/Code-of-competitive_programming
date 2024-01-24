#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

string s;
map<string, int> mp;
int n, p, ans;
char t;
void solve() {
    cin >> n >> p;
    for(int i = 1;i <= n;i ++) {
        cin >> s;
        scanf("%d", &mp[s]);
    }
    getchar();
    s = "";
    while(scanf("%c", &t) == 1) {
        if((t >= '0' && t <= '9') || (t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z')) s += t;
        else {
            ans = (ans + mp[s])  % p;
            s = "";
        }
    }
    cout << ans << '\n';
}

int main()
{
    solve();
    return 0;
}
