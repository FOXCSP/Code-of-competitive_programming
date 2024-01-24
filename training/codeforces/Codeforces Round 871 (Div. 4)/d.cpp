#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
#define SZ(T) ((int)T.size())
#define all(T) T.begin(), T.end()
#define lp (p<<1)
#define rp (p<<1|1)
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef double db;
// head


void solve(int CaseT) {
  int n, m;
  cin >> n >> m;
  priority_queue<int> heap;
  heap.push(n);
  while (!heap.empty()) {
    int top = heap.top();
    if (top == m) {
      cout << "YES\n";
      return ;
    }
    if (top % 3 == 0) {
      int p = top / 3;
      int q = top / 3 * 2;
      if (p == m || q == m || top == m) {
        cout << "YES\n";
        return ;
      }
      heap.push(p);
      heap.push(q);
    }
    heap.pop();
  }
  cout << "NO\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int _=1;
  cin>>_;
  for (int i = 1; i <= _; i++)
    solve(i);
  return 0;
}