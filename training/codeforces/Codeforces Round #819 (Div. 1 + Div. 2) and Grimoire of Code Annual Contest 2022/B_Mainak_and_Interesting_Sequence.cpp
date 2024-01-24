#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 100010;
int a[N], n, m;

void solve() {
    cin >> n >> m;
    if(m < n) {
        cout << "No\n";
        return ;
    }

    if(m % n == 0) {
        cout << "Yes\n";
        for(int i = 1; i <= n;i ++) cout << m/n << " \n"[i == n];
    }
    else {
        int t = n / 2;
        if(n % 2 == 0) t --;
        int s = 2 * t;
        if(m <= s) cout << "No\n";
        else {
            m -= s;
            if(n % 2 == 0 && m % 2 != 0) cout << "No\n";
            else {
                cout << "Yes\n";
                for(int i = 1;i <= t;i ++) cout << 1 << " " << 1 << " ";
                if(n % 2 == 0) cout << m / 2 << " " << m / 2 << '\n';
                else cout << m << "\n";
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) solve();
    return 0;
}
