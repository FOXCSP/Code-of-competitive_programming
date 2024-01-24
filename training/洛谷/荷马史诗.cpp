#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
      cin >> a[i];
  }
  pair<int, int> res(2e18, 0);
  for (int t = 0; t < m; t++) {
  	bool nono = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 1; i <= t; i++)
    	q.push({0, 0});
    for (const auto& ai : a) {
        q.push({ai, 0});
    }
    int ans1 = 0, ans2 = 0;
    while (q.size() != 1) {
      int sum = 0;
      bool f = false;
      if (q.size() < m) {
      	nono = 1;
      	break;
      }
      vector<int> vx;
      for (int i = 0; i < m; i++) {
        sum += q.top().first;
        vx.push_back(q.top().second + 1);
        q.pop();
      }
      int MAX = *max_element(vx.begin(), vx.end());
      q.push({sum, MAX});
      ans1 += sum;
      ans2 = max(ans2, MAX);
    }
    if (nono) continue;
    if (res.first > ans1) {
    	res.first = ans1;
    	res.second = ans2;
    }
	}
	cout << res.first << "\n" << res.second << '\n';
  return 0;
}