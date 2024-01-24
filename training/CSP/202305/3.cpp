#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define vec vector
#define lp (p << 1)
#define rp (p << 1 | 1)
#define pb push_back
#define P(T) pair<T, T>
#define SZ(T) (int)(T.size())
#define all(T) T.begin(), T.end()
#define setdb cout << fixed << setprecision(20);
using namespace std;
typedef double db;
typedef long long ll;
typedef long double ldb;
// -- head--

string str, ans;
int n, m, now;

int N(char s) {
  if (s <= '9') return (s - '0');
  else return 9 + (s - 'a' + 1);
}

int get(string s) {
  int x = N(s[0]) * (1 << 4) + N(s[1]);
  return x;
}

string work(int &i) {
  i += 2;
  string s = string(1, str[i]) + string(1, str[i + 1]);
  return s;
}

int find_pp(string s) {
  return (get(s) >> 2);
}

void dol(int o, int l) {
  if (o >= l) {
    for (int __ = 1, p = SZ(ans) - 2 * o; __ <= l; __++, p += 2) {
      cout << ans[p] << ans[p + 1];
      ans.pb(ans[p]);
      ans.pb(ans[p + 1]);
      now++;
      if (now % 8 == 0) cout << '\n';
    }
  } else {
    int L = SZ(ans);
    for (int __ = 1, p = L - 2 * o; __ <= l; __++) {
      cout << ans[p] << ans[p + 1];
      ans.pb(ans[p]);
      ans.pb(ans[p + 1]);
      if (p + 2 <= L - 1) p += 2;
      else p = L - 2 * o;
      now++;
      if (now % 8 == 0) cout << '\n';
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n; m = n / 8 + (n % 8);
  for (int i = 1; i <= m; i++) {
    string s; cin >> s;
    for (auto x : s) str.pb(x);
  }
  int Len = SZ(str);
  str = "#" + str;
  string byt = string(1, str[1]) + string(1, str[2]);
  vector<int> flg_num;
  bool flg = 0;
  for (int _ = 1; _ <= Len; byt = work(_)) {
    if (!flg) {
      if (N(str[_]) >> 3 & 1) {
      } else {
        flg = 1;
      }
    } else {
      int cur = get(byt) & 3;
      if (cur == 0) {
        // 字面量
        int pp = find_pp(byt);
        if (pp <= 59) {
          int l = pp + 1;
          while (l--) {
            byt = work(_);
            now++;
            cout << byt;
            for (auto x : byt) ans.pb(x);
            if (now % 8 == 0) cout << '\n';
          }
        } else {
          int l = pp - 59;
          int num = 0;
          vector<int> vx;
          if (l >= 1) vx.pb(get(work(_)));
          if (l >= 2) vx.pb(get(work(_)));
          if (l >= 3) vx.pb(get(work(_)));
          if (l >= 4) vx.pb(get(work(_)));
          for (int __ = SZ(vx) - 1, p = 0; __ >= 0; __--) {
            num = num * (1 << 8) + vx[__];
          }
          ++num;
          for (int __ = 1; __ <= num; __++) {
            ++now;
            byt = work(_);
            cout << byt;
            for (auto x : byt) ans.pb(x);
            if (now % 8 == 0) cout << '\n';
          }

        }
      } else if (cur == 2) {
        // 回溯2
        int O, l = (get(byt) >> 2);
        byt = work(_);
        O = get(byt);
        byt = work(_);
        O = get(byt) * (1 << 8) + O;
        dol(O, l + 1);
      } else if (cur == 1) {
        // 回溯1
        int a = N(str[_]), b = N(str[_ + 1]);
        int O = a >> 1, l = (a & 1) * (1 << 2) + (b >> 2);
        O = O * (1 << 8) + get(work(_));
        dol(O, l + 4);
      } else {
        // 非法
      }
    }
  }

  return 0;
}
