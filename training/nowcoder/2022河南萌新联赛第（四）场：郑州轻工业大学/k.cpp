#include <bits/stdc++.h>
#define fi first
#define se second
#define sf scanf
#define pf printf
#define int long long
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
//
LL gcd(LL x,LL y) {return !y ? x:gcd(y, x%y);}
LL qmi(LL a,LL b) {LL res=1; while(b) {if(b&1)res=res*a;a=a*a,b>>=1;}return res;}

/*--code --*/
const int N = 110;

void solve() {
    int n, x, cnt = 0;
	cin >> n >> x;
	std::vector<int> v;
	for(int i = 1;i <= n;i ++) {
		int a;
		cin >> a;
		if(x&a) {
			cout << "de: " << (x&a) << endl;
			x^=a,cnt++,v.push_back(i);
		}
	}
	if(!x)
        cout << v.size() << endl;
    else 
        cout << -1 << endl;

	if(!x) for(int i = 0;i < v.size();i ++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while( t --) {
    	solve();
    }
    return 0;
}
