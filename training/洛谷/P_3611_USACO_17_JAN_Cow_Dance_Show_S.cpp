#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using PII = pair<int,int>;

const int N = 10010;

int a[N], b[N], n, m;

bool check(int x) {
    priority_queue<int, vector<int>, greater<int> > heap;
    for(int i = 1;i <= x;i ++) {
        heap.push(a[i]);
    }
    for(int i = x + 1; i <= n; i ++) {
        int t = heap.top(); heap.pop();
        if(t + a[i] > m) return false;
        heap.push(t + a[i]);
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n;i ++) cin >> a[i];
    int l = 1, r = n;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
