#include <bits/stdc++.h>
// #define int long long
#define lp (p<<1)
#define rp (p<<1|1)
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vi vector<int>
#define SZ(x) ((int)x.size())
#define vl vector<ll>;
#define vpp vector<pii>
#define lep(i, x, y) for (int i=(x);i<=(y);i++)
#define rep(i, y, x) for (int i=(y);i>=(x);i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
ll qmi(ll a, ll b, ll mod) 
{ll res=1; while(b) {if(b&1) res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
int gcd(int a, int b) {return !b?a:gcd(b,a%b);}
inline ll read() {
	ll s=0,f=1; char c = getchar();
	while (c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while ('0'<= c&&c<='9') {s=s*10+c-'0';c=getchar();}
	return s*f;
}
void print(ll x) {if (!x) return ; if (x>9) print(x/10); putchar(x%10+'0');}
const int Mod = 1e9+7;
// --head--

const int N = 200010;
vpp e[N];
int n, m, k, button[N];
int dist[N], st[N];
struct name {
    int d, u, ty;
    bool operator < (const name& B) const {
        return d < B.d;
    }
    bool operator > (const name& B) const {
    	return d > B.d;
    }
};
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<name, vector<name>, greater<name>> heap;
    heap.push(name{0, 1, 0});
    while (!heap.empty()) {
        auto [d, u, cnt] = heap.top(); heap.pop();
        if (st[u] > 1) continue;
        st[u]++;
        for (auto [v, ty] : e[u]) {
            if (ty == 1 && cnt % 2 == 0) {
                heap.push({d + 1, v, cnt});
            }
            if (ty == 1 && cnt % 2 != 0 && button[u]) {
                heap.push({d + 1, v, cnt + 1});
            }
            if (ty == 0 && cnt % 2 != 0) {
                heap.push({d + 1, v, cnt});
            }
            if (ty == 0 && cnt % 2 == 0 && button[u]) {
                heap.push({d + 1, v, cnt + 1});
            }
            dist[v] = min(dist[v], dist[u] + 1);
        }
    }
    if (dist[n] == 0x3f3f3f3f) cout << "-1\n";
    else cout << dist[n] << '\n';
}

void solve() {
    cin >> n >> m >> k;
    lep(i, 1, m) {
        int u, v, a; cin >> u >> v >> a;
        e[u].pb({v, a});
        e[v].pb({u, a});
    }
    lep(i, 1, k) {
        int x; cin >> x;
        button[x] = 1;
    }
  	dijkstra();
}

int main() {
	solve();
	return 0;
}