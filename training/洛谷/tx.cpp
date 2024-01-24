#include <bits/stdc++.h>
// #define int long long
#define cf int _; cin>>_; while(_--) solve();
using namespace std;
using PII = pair<int,int>;
using ll = long long;

const int N = 200010;
int n;
vector<int> vx, cnt;
vector<int>a;
void solve() {
    scanf("%d", &n);
    int ans = n;
    vx.clear(), a.clear();
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        vx.push_back(x);
        a.push_back(x);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    for (auto c : vx) cnt.push_back(0);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int px = lower_bound(vx.begin(), vx.end(), x) - vx.begin();
        cnt[px]++;
    }
    int id = n;
    while(id && ans) {
        id --;
        vector<int> erx;
        for (int i = 0; i < vx.size() - 1; i++) {
            int x = 1 << 30;
            if (cnt[i] == 0) continue;
            x = min(cnt[i], cnt[i + 1]);
            cnt[i] -= x;
            cnt[i + 1] -= x;
            ans -= x * 2;
            if (cnt[i] == 0) erx.push_back(i);
            if (cnt[i + 1] == 0) erx.push_back(i + 1);
        }
        for (int i = erx.size() - 1; i >= 0; i--) {
            vx.erase(vx.begin() + erx[i]);
            cnt.erase(cnt.begin() + erx[i]);
        }
    }
    printf("%d\n", ans);
}

int main() {
	cf
	return 0;
}