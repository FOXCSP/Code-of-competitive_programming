#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 2e5+10;
int a[N];
vector<int>cnt;
ll ans = 0;
void solve () {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    for(int i = 0;i < n; ) {
        if(s[i] == 'Z') {
            int j = i + 1;
            while(j < n && s[j] == 'Z') {
                j ++;
                ans += 4;
            }
            i = j;
            while(j < n && s[j] == 'z') {
                j ++;
            }
            if(j != n) cnt.push_back(j - i);
            i = j;
        }
        else while(i < n && s[i] == 'z') i ++;
    }
    sort(cnt.begin(), cnt.end());
    for(int i = 0; i < cnt.size(); i ++) {
        if(k >= cnt[i]) {
            k -= cnt[i];
            ans += 4;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
