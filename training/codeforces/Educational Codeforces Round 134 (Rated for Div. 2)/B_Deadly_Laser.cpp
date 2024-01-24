#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1010;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int d[N][N];
int n, m , s, t, p;

void solve() {
	cin >> n >> m >> s >> t >> p;
    if((abs(1-s) <= p || abs(m - t) <= p) && (abs(1-t) <= p || abs(n-s) <= p)) {
        cout << -1 << endl;
    }
    else {
        cout << (n + m - 2) << endl;
    }
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while(T --) solve();
	return 0;
}
