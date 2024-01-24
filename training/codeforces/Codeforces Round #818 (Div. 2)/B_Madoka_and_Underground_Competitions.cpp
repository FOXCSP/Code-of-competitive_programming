#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 510;
char ch[N][N];
int n, k, r, c;

void solve() {
    cin >> n >> k >> r >> c;
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n; j ++) {
			int t = abs((i + j) - (r + c));
			if(t % k == 0)
				cout << "X";
			else cout << ".";
		}
		cout << "\n";
	}
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
