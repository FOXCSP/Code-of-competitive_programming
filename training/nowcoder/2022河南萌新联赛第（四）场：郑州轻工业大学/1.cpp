#include <bits/stdc++.h>
#define fi first
#define se second
#define sf scanf
#define pf printf
//#define int long long
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
//
LL gcd(LL x,LL y) {return !y ? x:gcd(y, x%y);}
LL qmi(LL a,LL b) {LL res=1; while(b) {if(b&1)res=res*a;a=a*a,b>>=1;}return res;}

/*--code --*/

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << (23&3) << endl;
    return 0;
}
