#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 50010;
PII range[N];
int n, m;

void solve() {
    cin >> n;
    for(int i = 1;i <= n;i ++) {
        cin >> range[i].first >> range[i].second;
    }
    sort(range + 1, range + n + 1);
    int l = range[1].first, r = range[1].second;
    for(int i = 2;i <= n; i ++) {
        if(range[i].first <= r)
            r = max(r, range[i].second);
        else {
            cout << l << " " << r << '\n';
            l = range[i].first;
            r = range[i].second;
        }
    }
    cout << l << " " << r << "\n";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
