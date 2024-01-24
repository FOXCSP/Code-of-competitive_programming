#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

int n;

void solve() {
    cin >> n;
    unordered_map<string, int> mp, t1, t2, t3;
    for(int i = 1;i <= 3;i ++) {
        for(int j = 1;j <= n;j ++) {
            string s;
            cin >> s;
            if(i == 1 && t1.count(s) == 0) mp[s] += 1, t1[s] = 1;
            if(i == 2 && t2.count(s) == 0) mp[s] += 2, t2[s] = 2;
            if(i == 3 && t3.count(s) == 0) mp[s] += 4, t3[s] = 3;
        }
    }
    int cnt[5];
    memset(cnt, 0, sizeof cnt);
    for(auto s : mp) {
        if(s.second >= 7) continue;
        if(s.second == 1) cnt[1] += 3;
        if(s.second == 2) cnt[2] += 3;
        if(s.second == 4) cnt[3] += 3;
        if(s.second == 3) cnt[1] += 1, cnt[2] += 1;
        if(s.second == 5) cnt[1] += 1, cnt[3] += 1;
        if(s.second == 6) cnt[2] += 1, cnt[3] += 1;
    }
    for(int  i = 1;i <= 3;i ++) cout << cnt[i] << " \n"[i == 3];
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
