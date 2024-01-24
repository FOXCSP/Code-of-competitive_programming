#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define SZ(T) (int(T.size()))
#define all(T) T.begin(), T.end()
using namespace std;
map<int, vector<pair<int, int>>> mp_hs;
map<pair<int, int>, vector<int>> mp_pr;
int n, m;
vector<int> AND(vector<int> a, vector<int> b) {
  vector<int> ret;
  b.pb(2e9);
  sort(all(b));
  for (auto x : a) {
    int p = *lower_bound(all(b), x);
    if (p == x) ret.pb(x);
  }
  return ret;
}
vector<int> OR(vector<int> a, vector<int> b) {
  vector<int> ret = a;
  for (auto x : b) ret.pb(x);
  sort(all(ret));
  ret.erase(unique(all(ret)), ret.end());
  return ret;
}
vector<int> op_one(int a, int b) {
  vector<int> ret = mp_pr[{a, b}];
  return ret;
}
vector<int> op_two(int a, int b) {
  vector<int> ret;
  auto cur = mp_hs[a];
  for (auto x : cur) {
    if (x.se != b) ret.pb(x.fi);
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int dn; cin >> dn;
    int x; cin >> x;
    for (int j = 1; j <= x; j++) {
      int id, idx; cin >> id >> idx;
      mp_pr[{id, idx}].pb(dn);
      mp_hs[id].pb({dn, idx});
    }
  }

  cin >> m;
  for (int _ = 1; _ <= m; _++) {
    string s;
    cin >> s;
    // cerr << s << '\n';
    // stack<char> stk;
    string stk;
    stack<vector<int>> stk_vec;
    bool f = 1;
    int a = 0, b = 0;
    char op;
    int len = SZ(s);
    s = s + "#";
    for (int i = 0; i <= len; i++) {
      if (s[i] == '&' || s[i] == '|' || s[i] == '(') {
        stk.pb(s[i]);
      } else if ('0' <= s[i] && s[i] <= '9') {
        if (f) a = a * 10 + s[i] - '0';
        else   b = b * 10 + s[i] - '0';
      } else if (s[i] == ':' || s[i] == '~') {
        f = 0;
        op = s[i];
      } else if (s[i] == '#' || s[i] == ')') {
        if (a != 0 && b != 0) {
          // cerr << a << " " << b << " xx\n";
          if (op == ':') stk_vec.push(op_one(a, b));
          else stk_vec.push(op_two(a, b));
        }
        if (s[i] == ')') {
          while (stk.back() != '(') {
            auto of = stk.back(); stk.pop_back();
            auto p1 = stk_vec.top(); stk_vec.pop();
            auto p2 = stk_vec.top(); stk_vec.pop();
            if (of == '&') {
              stk_vec.push(AND(p1, p2));
            } else {
              stk_vec.push(OR(p1, p2));
            }
          }
          stk.pop_back();
        }
        // cerr << stk << " now\n";
        // cerr << SZ(stk_vec) << '\n';
        a = 0, b = 0; f = 1;
      }
    }
  
    while (!stk.empty()) {
      char op = stk.back(); stk.pop_back();
      auto p1 = stk_vec.top();stk_vec.pop();
      auto p2 = stk_vec.top();stk_vec.pop();
      vector<int> x;
      if (op == '&') {
        x = AND(p1, p2);
      } else {
        x = OR(p1, p2);
      }
      stk_vec.push(x);
    }
    auto x = stk_vec.top();
    if (SZ(x) == 0) cout << "\n";
    else {
      sort(all(x));
      for (int i = 0; i < SZ(x); i++) {
        cout << x[i] << " \n"[i == SZ(x) - 1];
      }
    }
  }

  return 0;
}
