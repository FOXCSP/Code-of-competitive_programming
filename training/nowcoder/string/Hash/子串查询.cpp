#include <bits/stdc++.h>
// #define int long long
using namespace std;
using ll = long long;
using umap = unordered_map<int,int>;
using pii = pair<int,int>;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}

const int N = 1e5+10;
vector<int> pos[30];
char str[N];
void solve() {
    int n, m; cin >> n >> m;
    cin >> str + 1;
    for(int i = 1; i <= n;i ++) {
        pos[str[i] - 'a'].push_back(i);
    }
    while(m --) {
        cin >> str + 1;
        int len = strlen(str+1);
        int now = 0, flag = 1;
        for(int i = 1;i <= len;i ++) {
            int l = 0, r = pos[str[i] - 'a'].size() - 1;
            if(r < 0) { flag = 0; break;}
            while(l < r) {
                int mid = l + r >> 1;
                if(pos[str[i] - 'a'][mid] > now) r = mid;
                else l = mid + 1;
            }
            if(pos[str[i] - 'a'][l] > now) now = pos[str[i] - 'a'][l];
            else { flag = 0; break;}
        }
        if(flag) cout << "YES\n";
        else cout  << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    solve();
    return 0;
}
