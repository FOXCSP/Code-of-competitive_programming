#include <bits/stdc++.h>
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define SZ(T) ((int)(T.size()))
#define all(T) T.begin(), T.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
// head

const int N = 1000010;
int c[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m, k, mx = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    c[l] += 1, c[r] -= 1;
    mx = max(mx, r);
  }

  for (int i = 1; i <= mx + 1; i++)
    c[i] += c[i - 1];
  
  cout << ceil(*max_element(c + 1, c + mx + 1) / k) << '\n';

  return 0;
} 
