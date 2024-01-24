#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
ll qmi(ll a,ll b) {ll res=1;while(b){if(b&1)res=(ll)res*a;a=a*a;b>>=1;}return res;}

void solve() {
    int n;
    std::cin >> n;
    if(n & 1) {
        std::cout << 1 << " ";
        for(int i = 2;i <= n;i ++) {
            if(i&1) std::cout << i - 1 << " ";
            else std::cout << i + 1 << " ";
        }
    }
    else {
        for(int i = 1;i <= n;i ++) {
            if(i&1) std::cout << i + 1 << " ";
            else std::cout << i - 1 << " ";
        }
    }
    std::cout << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while(T --) {
        solve();
    }
    return 0;
}
