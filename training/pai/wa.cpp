#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(T) (int)(T.size())
using ll = long long;
const ll mod = 1000000007;

struct node {
  int id, mx, mn;
};

void solve() {
  int k, n;
  cin >> k;
  vector<vector<int>> vx(k + 1);
  for (int i = 1; i <= k; i++) {
    int c; cin >> c;
    for (int j = 1; j <= c; j++) {
      int x; cin >> x;
      vx[i].pb(x);
    }
    sort(vx[i].begin(), vx[i].end());
  }

  int ans = 1e9;
  vector<int> res;
  auto get = [&](int t) {
    queue<node> que; 
    que.push({1, t, t});
    while (que.size()) {
      auto x = que.front(); que.pop();
      int i = x.id, mx = x.mx, mn = x.mn;
      if (i == k) {
        ans = min(ans, mx - mn); 
      }
      
      // if (t == 10) {
      //   cerr << " " << i << " " << mn << " " << mx << '\n';
      // }


      ++i;
      if (i > k) continue;
      int m = SZ(vx[i]);
      int p = lower_bound(vx[i].begin(), vx[i].end(), mn) - vx[i].begin();
      int now;
      if (p == m) {
        p--;
        now = vx[i][p];
        mx = max(mx, now);
        mn = min(mn, now);
        que.push({i, mx, mn});
      } else if (p == 0) {
        now = vx[i][p];
        mx = max(mx, now);
        mn = min(mn, now);
        que.push({i, mx, mn});
      } else {
        int u = vx[i][p] - mn;
        int v = mx - vx[i][p - 1];
        if (u < v) {
          now = vx[i][p];
          mx = max(mx, now);
          mn = min(mn, now);
          que.push({i, mx, mn});
        } else if (v < u) {
          now = vx[i][p - 1];
          mx = max(mx, now);
          mn = min(mn, now);
          que.push({i, mx, mn});
        } else {
          que.push({i, max(mx, vx[i][p]), min(mn, vx[i][p])});
          que.push({i, max(mx, vx[i][p - 1]), min(mn, vx[i][p - 1])});
        }
      }
    }
    return ;
  };

  for (auto x : vx[1]) {
    get(x);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int _;
  cin >> _;
  for (int i = 1; i <= _; i++) solve();
  return 0;
}
