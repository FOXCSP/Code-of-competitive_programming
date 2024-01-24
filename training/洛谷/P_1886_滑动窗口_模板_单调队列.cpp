#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e6+10;
int q[N], k;
int a[N];
void solve() {
    int n;
    cin >> n >> k;
    int hh = 0, tt = -1;
    for(int i = 0;i < n;i ++) cin >> a[i];
    for(int i = 0;i < n;i ++) {
        while(hh <= tt && i - k + 1 > q[hh]) hh ++;
        while(hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k - 1) cout << a[q[hh]] << ' ';
    }
    cout << "\n";
    hh = 0, tt = -1;
    for(int i = 0;i < n;i ++) {
        while(hh <= tt && i - k + 1 > q[hh]) hh ++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++ tt] = i;
        if(i >= k - 1) cout << a[q[hh]] << ' ';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
