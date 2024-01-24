#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 300010;
int n;
int a[N], num[10];
int b[N];
umap mp, ed;
void solve() {
    memset(num, 0, sizeof num);
    mp.clear();
    ed.clear();
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n; i ++) {
        cin >> a[i];
        mp[a[i]] ++;
    }
    for(int i = 1;i <= n; i ++) {
        cin >> b[i];
        if(b[i] < 10) continue;
        if(mp[b[i]] > 0) ed[b[i]] ++, mp[b[i]] --;
        else b[i] = int(log10(b[i]) + 1), cnt ++;
    }
    for(int i = 1;i <= n;i ++) {
        if(a[i] < 10) continue;
        if(ed[a[i]] <= 0) a[i] = int(log10(a[i]) + 1), cnt ++;
        else ed[a[i]] --;
    }
    // for(int i = 1;i <= n;i ++) cout << a[i] << " \n"[i == n];
    // for(int i = 1;i <= n;i ++) cout << b[i] << " \n"[i == n];
    for(int i = 1; i <= n;i ++) {
        if(a[i] < 10) num[a[i]] ++;
        if(b[i] < 10) num[b[i]] --;
    }
    for(int i = 1;i < 10;i ++)
        if(num[i] != 0 && i != 1)
            cnt += abs(num[i]);
    cout << cnt << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
